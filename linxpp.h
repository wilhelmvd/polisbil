#include <linx.h> //linx.h is the interface for the LINX library, liblinx.a

class Linx {
	LINX *endpoint;
public:
	Linx(const char *);
	~Linx(void);

	union LINX_SIGNAL *alloc(size_t, LINX_SIGSELECT);
	void free_buf(union LINX_SIGNAL **);
	int send(union LINX_SIGNAL **, LINX_SPID);
	int receive(union LINX_SIGNAL **, const LINX_SIGSELECT *);
	int hunt(const char *, union LINX_SIGNAL **);
	LINX_SPID sender(union LINX_SIGNAL **);
	int get_descriptor(void);
	int send_w_s(union LINX_SIGNAL **, LINX_SPID, LINX_SPID);
	int send_w_opt(union LINX_SIGNAL **, LINX_SPID, LINX_SPID, int32_t *);
	int sigattr(const union LINX_SIGNAL **, uint32_t, void **);
	int receive_w_tmo(union LINX_SIGNAL **, LINX_OSTIME, const LINX_SIGSELECT *);
	int receive_from(union LINX_SIGNAL **, LINX_OSTIME, const LINX_SIGSELECT *, LINX_SPID);
	LINX_OSBUFSIZE sigsize(union LINX_SIGNAL **);
	int set_sigsize(union LINX_SIGNAL **, LINX_OSBUFSIZE);
	int hunt_from(const char *, union LINX_SIGNAL **, LINX_SPID);
	LINX_OSATTREF attach(union LINX_SIGNAL **, LINX_SPID);
	int detach(LINX_OSATTREF *);
	LINX_SPID get_spid(void);
	int get_name(LINX_SPID, char **);
	int free_name(char **);
	pid_t get_owner(LINX_SPID);
	int get_stat(LINX_SPID, struct linx_info_stat **);
	int free_stat(struct linx_info_stat **);
	LINX_OSTMOREF request_tmo(LINX_OSTIME, union LINX_SIGNAL **);
	int cancel_tmo(LINX_OSTMOREF *);
	int modify_tmo(LINX_OSTMOREF *, LINX_OSTIME);
	LINX_NLREF request_new_link(LINX_NLTOKEN);
	int cancel_new_link(LINX_NLREF *);
	int get_version(char *);
};
