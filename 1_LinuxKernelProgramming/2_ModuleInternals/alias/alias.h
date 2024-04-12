/*Let's see the definition of this macro, it is present in linux/module.h*/
/*Each module must use one module_init()*/
#define module_init(initfn)
	static inline initcall_t __inittest(void)
	{ return initfn; }
	int init_module(void) __attribute__((alias(#initfn)));
	
/*This is only required if you want to be unloadable*/
#define module_exit(exitfn)
	static inline exitcall_t __exittest(void)
	{ return exitfn; }
	void cleanup_module(void) __attribute__((alias(#exitfn)));
