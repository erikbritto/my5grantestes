#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x6e5e9ea5, "module_layout" },
	{ 0xc043d1be, "ip_tunnel_get_stats64" },
	{ 0x50049ec8, "single_release" },
	{ 0xc353a5e3, "seq_read" },
	{ 0xddfb6d9e, "seq_lseek" },
	{ 0xab633e4c, "rtnl_link_unregister" },
	{ 0xe1c50fb2, "genl_unregister_family" },
	{ 0x4a80c07f, "unregister_pernet_subsys" },
	{ 0x1a1279de, "remove_proc_entry" },
	{ 0xf914135c, "proc_create" },
	{ 0xb6ac6f8d, "proc_mkdir" },
	{ 0xe3876c9b, "register_pernet_subsys" },
	{ 0x63b60daf, "genl_register_family" },
	{ 0xb21467d8, "rtnl_link_register" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x1d1062d0, "setup_udp_tunnel_sock" },
	{ 0xbb0e920e, "register_netdevice" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd23ba18f, "fput" },
	{ 0xb62c92f4, "sockfd_lookup" },
	{ 0xfd6910bf, "netif_rx" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x668bcbab, "__iptunnel_pull_header" },
	{ 0xa8ae55b3, "ip_local_out" },
	{ 0x8db2bf10, "eth_type_trans" },
	{ 0xd506abfc, "__netdev_alloc_skb" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x9166fada, "strncpy" },
	{ 0x984ce9bd, "__nla_parse" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0xd02ea711, "unregister_netdevice_queue" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x13add853, "pskb_expand_head" },
	{ 0xa2d53c7b, "kfree_skb" },
	{ 0x9eae889d, "netlink_unicast" },
	{ 0xa3470d57, "__alloc_skb" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa6fcf7db, "skb_trim" },
	{ 0xa2694267, "genlmsg_put" },
	{ 0xf163e0f9, "kmem_cache_alloc_trace" },
	{ 0xe157ef13, "kmalloc_caches" },
	{ 0xcd55165d, "__put_net" },
	{ 0xb53602f6, "dev_get_by_index_rcu" },
	{ 0xa0209ab1, "get_net_ns_by_fd" },
	{ 0x51e42b1d, "__pskb_pull_tail" },
	{ 0xc1e5dd2f, "skb_copy_bits" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x3e723d6d, "release_sock" },
	{ 0x4cec8c45, "lock_sock_nested" },
	{ 0x7b0d34c, "sock_sendmsg" },
	{ 0xe29f154b, "iov_iter_init" },
	{ 0xf8aae665, "current_task" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x5faea49e, "sk_free" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xc5e4a5d1, "cpumask_next" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x754d539c, "strlen" },
	{ 0x85b9751a, "sock_create" },
	{ 0xe97c9aab, "sock_release" },
	{ 0xe5e9ec57, "consume_skb" },
	{ 0x9d1beb28, "udp_tunnel_xmit_skb" },
	{ 0xbb17386f, "__icmp_send" },
	{ 0x8ec118c, "skb_push" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0x349cba85, "strchr" },
	{ 0x971b7e10, "dst_release" },
	{ 0x2d931fa2, "ip_route_output_flow" },
	{ 0x6e3cd53f, "nla_put" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x37a0cba, "kfree" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xc5850110, "printk" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xa916b694, "strnlen" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xd1639f17, "seq_printf" },
	{ 0x19867527, "single_open" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "udp_tunnel");


MODULE_INFO(srcversion, "B486BDA7ADE71AF01FCDDBD");
