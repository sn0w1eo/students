#include "destroy.h"


void destroy_all(Object* obj) {
	obj->rc = sem_destroy(&obj->sem);
	ExitOnError(obj->rc, __LINE__);

	obj->rc = pthread_cond_destroy(&obj->cond_main);
	ExitOnError(obj->rc, __LINE__);

	obj->rc = pthread_cond_destroy(&obj->cond_thread);
	ExitOnError(obj->rc, __LINE__);

	obj->rc = pthread_mutex_destroy(&obj->wg.mu);
	ExitOnError(obj->rc, __LINE__);
}