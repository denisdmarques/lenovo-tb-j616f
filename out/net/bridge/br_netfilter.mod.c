#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xdeeaadc, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xba3222a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xec52c4a, __VMLINUX_SYMBOL_STR(pskb_trim_rcsum_slow) },
	{ 0x26faba50, __VMLINUX_SYMBOL_STR(unregister_net_sysctl_table) },
	{ 0x92df2187, __VMLINUX_SYMBOL_STR(ip_do_fragment) },
	{ 0x8a997e1d, __VMLINUX_SYMBOL_STR(proc_dointvec) },
	{ 0xc61dfa3f, __VMLINUX_SYMBOL_STR(dst_release) },
	{ 0x50835ae1, __VMLINUX_SYMBOL_STR(__vlan_find_dev_deep_rcu) },
	{ 0xd2da1048, __VMLINUX_SYMBOL_STR(register_netdevice_notifier) },
	{ 0xada06c5f, __VMLINUX_SYMBOL_STR(neigh_destroy) },
	{ 0x9d0d6206, __VMLINUX_SYMBOL_STR(unregister_netdevice_notifier) },
	{ 0x96cb1f8, __VMLINUX_SYMBOL_STR(nf_hook_slow) },
	{ 0x66edb1ae, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0xd161670b, __VMLINUX_SYMBOL_STR(unregister_pernet_subsys) },
	{ 0x7483cd75, __VMLINUX_SYMBOL_STR(br_dev_queue_push_xmit) },
	{ 0x985558a1, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xa2437a41, __VMLINUX_SYMBOL_STR(nf_unregister_net_hooks) },
	{ 0x4474a939, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x2469810f, __VMLINUX_SYMBOL_STR(__rcu_read_unlock) },
	{ 0x43b0c9c3, __VMLINUX_SYMBOL_STR(preempt_schedule) },
	{ 0xdbd179d, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x831f889d, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x99406352, __VMLINUX_SYMBOL_STR(br_forward_finish) },
	{ 0xcaf343df, __VMLINUX_SYMBOL_STR(ip_route_input_noref) },
	{ 0x34942c6f, __VMLINUX_SYMBOL_STR(nf_ipv6_ops) },
	{ 0x6176413e, __VMLINUX_SYMBOL_STR(nf_register_net_hooks) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xd463104d, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0x6b2dc060, __VMLINUX_SYMBOL_STR(dump_stack) },
	{ 0x195c7769, __VMLINUX_SYMBOL_STR(register_pernet_subsys) },
	{ 0xad3ba59a, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0xcab796c4, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4b933fe0, __VMLINUX_SYMBOL_STR(skb_pull_rcsum) },
	{ 0x2535c935, __VMLINUX_SYMBOL_STR(ip_route_output_flow) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x2c39a116, __VMLINUX_SYMBOL_STR(nf_br_ops) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x85670f1d, __VMLINUX_SYMBOL_STR(rtnl_is_locked) },
	{ 0x4c88bf36, __VMLINUX_SYMBOL_STR(br_handle_frame_finish) },
	{ 0x8d522714, __VMLINUX_SYMBOL_STR(__rcu_read_lock) },
	{ 0xd397a642, __VMLINUX_SYMBOL_STR(register_net_sysctl) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D559E0AC1D8BE416C9C2C71");
