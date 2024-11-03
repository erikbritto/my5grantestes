#!/bin/bash

# Check if at least 3 arguments are provided
if [ $# -lt 3 ]; then
    echo -e "\nUsage: $0 [division|decrement|parallel] num_ue delay interval divdec repetitions\n"
    exit 0
fi

# Check if the first argument is "division", "decrement" or "parallel"
if [[ "$1" != "division" && "$1" != "decrement" && "$1" != "parallel" ]]; then
    echo -e "\nError: The first argument must be 'division', 'decrement', or 'parallel'\n"
    exit 1
fi

# Assign the first argument to the test variable
test=$1

# Check the number of arguments based on the test
if [[ "$test" == "parallel" ]]; then
    if [ $# -ne 4 ]; then
        echo -e "\nUsage for 'parallel': $0 parallel num_ue delay repetitions\n"
        exit 1
    fi
    num_ue=$2
    delay=$3
    repetitions=$4
else
    if [ $# -ne 6 ]; then
        echo -e "\nUsage for 'division' or 'decrement': $0 [division|decrement] num_ue delay interval factor repetitions\n"
        exit 1
    fi
    num_ue=$2
    delay=$3
    interval=$4
    divdec=$5
    repetitions=$6
fi

# Loop through the number of repetitions
for i in $(seq 1 $repetitions); do
    if [[ "$test" == "parallel" ]]; then
        test_name=my5grantester_open5gs_${test}_${num_ue}_0_${i}.csv
    else
        test_name=my5grantester_open5gs_${test}_${num_ue}_${delay}_${divdec}_${interval}_0_${i}.csv
    fi

    # Path to the YAML file
    yaml_file="../Deployment/tester/my5grantester.yaml"
    copy_file="../Deployment/tester/my5grantester2.yaml" 

    cp $yaml_file $copy_file

    # Update the YAML file with the provided values
    sed -i 's/\$TEST\b/'"$test"'/g' $copy_file
    sed -i 's/\$NUM_UE\b/'"$num_ue"'/g' $copy_file
    sed -i 's/\$DELAY\b/'"$delay"'/g' $copy_file

    # Only update INTERVAL and FACTOR if operation is not parallel
    if [[ "$test" != "parallel" ]]; then
        sed -i 's/\$INTERVAL\b/'"$divdec"'/g' $copy_file
        sed -i 's/\$CONSTANT\b/'"$interval"'/g' $copy_file
    fi

    kubectl apply -f $copy_file

    rm $copy_file

    cd ../Deployment
    python3 start.py

    kubectl port-forward deployment/open5gs-mongodb 63145:27017 --namespace cemenin &
    PORT_FORWARD_PID=$!

    python3 insereDados.py
    kill $PORT_FORWARD_PID

    echo "Running experiment $i"

    # Number of UEs and gnBs
    kubectl scale --replicas=50 statefulsets open5gs-my5grantester --namespace cemenin

    # Delay
    echo "Waiting connections for experiment"
    sleep 250

    echo "Waiting for experiment to finish"
    sleep 1100

    cd ../Data
    ./capture_and_parse_logs.sh $test_name

    echo "Clear experiment environment"
    kubectl scale --replicas=0 statefulsets open5gs-my5grantester --namespace cemenin

    # Delete tester pods
    for j in $(seq 0 $((49))); do
        kubectl delete pod open5gs-my5grantester-$j --namespace cemenin &
    done

    cd ../Deployment
    python3 remove.py
    sleep 60
done
