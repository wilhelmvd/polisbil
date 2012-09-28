#include <linxpp.h>

Linx::Linx(const char *name)
{
	endpoint = linx_open(name, 0, NULL);
}

Linx::~Linx(void)
{
	linx_close(endpoint);
}

//methods

union LINX_SIGNAL *Linx::alloc(size_t size, LINX_SIGSELECT sig_no)
{
	return linx_alloc(endpoint, size, sig_no);
}

void Linx::free_buf(union LINX_SIGNAL **sig)
{
	(void)linx_free_buf(endpoint, sig);
}

int Linx::send(union LINX_SIGNAL **sig, LINX_SPID to)
{
	return linx_send(endpoint, sig, to);
}

int Linx::receive(union LINX_SIGNAL **sig, const LINX_SIGSELECT *sig_sel)
{
	return linx_receive(endpoint, sig, sig_sel);
}

int Linx::hunt(const char *name, union LINX_SIGNAL **hunt_sig)
{
	return linx_hunt(endpoint, name, hunt_sig);
}

LINX_SPID Linx::sender(union LINX_SIGNAL **sig)
{
	return linx_sender(endpoint, sig);
}

int Linx::get_descriptor(void)
{
	return linx_get_descriptor(endpoint);
}

int Linx::send_w_s(union LINX_SIGNAL **sig, LINX_SPID from, LINX_SPID to)
{
	return linx_send_w_s(endpoint, sig, from, to);
}

int Linx::send_w_opt(union LINX_SIGNAL **sig, LINX_SPID from, LINX_SPID to, int32_t *taglist)
{
	return linx_send_w_opt(endpoint, sig, from, to, taglist);
}

int Linx::sigattr(const union LINX_SIGNAL **sig, uint32_t attr, void **value)
{
	return linx_sigattr(endpoint, sig, attr, value);
}

int Linx::receive_w_tmo(union LINX_SIGNAL **sig, LINX_OSTIME tmo, const LINX_SIGSELECT * sig_sel)
{
	return linx_receive_w_tmo(endpoint, sig, tmo, sig_sel);
}

int Linx::receive_from(union LINX_SIGNAL **sig, LINX_OSTIME tmo, const LINX_SIGSELECT * sig_sel, LINX_SPID from)
{
	return linx_receive_from(endpoint, sig, tmo, sig_sel, from);
}

LINX_OSBUFSIZE Linx::sigsize(union LINX_SIGNAL **sig)
{
	return linx_sigsize(endpoint, sig);
}

int Linx::set_sigsize(union LINX_SIGNAL **sig, LINX_OSBUFSIZE sigsize)
{
	return linx_set_sigsize(endpoint, sig, sigsize);
}

int Linx::hunt_from(const char *name, union LINX_SIGNAL **hunt_sig, LINX_SPID from)
{
	return linx_hunt_from(endpoint, name, hunt_sig, from);
}

LINX_OSATTREF Linx::attach(union LINX_SIGNAL **sig, LINX_SPID spid)
{
	return linx_attach(endpoint, sig, spid);
}

int Linx::detach(LINX_OSATTREF * attref)
{
	return linx_detach(endpoint, attref);
}

LINX_SPID Linx::get_spid(void)
{
	return linx_get_spid(endpoint);
}

int Linx::get_name(LINX_SPID spid, char **name)
{
	return linx_get_name(endpoint, spid, name);
}

int Linx::free_name(char **name)
{
	return linx_free_name(endpoint, name);
}

pid_t Linx::get_owner(LINX_SPID spid)
{
	return linx_get_owner(endpoint, spid);
}

int Linx::get_stat(LINX_SPID spid, struct linx_info_stat **stat)
{
	return linx_get_stat(endpoint, spid, stat);
}

int Linx::free_stat(struct linx_info_stat **stat)
{
	return linx_free_stat(endpoint, stat);
}

LINX_OSTMOREF Linx::request_tmo(LINX_OSTIME tmo, union LINX_SIGNAL **sig)
{
	return linx_request_tmo(endpoint, tmo, sig);
}

int Linx::cancel_tmo(LINX_OSTMOREF * tmoref)
{
	return linx_cancel_tmo(endpoint, tmoref);
}

int Linx::modify_tmo(LINX_OSTMOREF * tmoref, LINX_OSTIME tmo)
{
	return linx_modify_tmo(endpoint, tmoref, tmo);
}

LINX_NLREF Linx::request_new_link(LINX_NLTOKEN token)
{
	return linx_request_new_link(endpoint, token);
}

int Linx::cancel_new_link(LINX_NLREF *nlref)
{
	return linx_cancel_new_link(endpoint, nlref);
}

int Linx::get_version(char *buf)
{
	return linx_get_version(buf);
}
