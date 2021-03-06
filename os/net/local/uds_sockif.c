/****************************************************************************
 * net/socket/net_sockif.c
 *
 *   Copyright (C) 2017-2018 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <errno.h>
#include <debug.h>

#include <tinyara/net/net.h>

#include "local/local.h"
#include "local/uds_socket.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: net_sockif
 *
 * Description:
 *   Return the socket interface associated with this address family.
 *
 * Input Parameters:
 *   family   - Socket address family
 *   type     - Socket type
 *   protocol - Socket protocol
 *
 * Returned Value:
 *   On success, a non-NULL instance of struct sock_intf_s is returned.  NULL
 *   is returned only if the address family is not supported.
 *
 ****************************************************************************/

FAR const struct sock_intf_s *
net_sockif(sa_family_t family, int type, int protocol)
{
	FAR const struct sock_intf_s *sockif = NULL;

	/* Get the socket interface.
	 *
	 * REVISIT:  Should also support PF_UNSPEC which would permit the socket
	 * to be used for anything.
	 */

	switch (family) {
#ifdef CONFIG_NET_LOCAL
	case PF_LOCAL:
		sockif = &g_local_sockif;
		break;
#endif
	default:
		ndbg("ERROR: Address family unsupported: %d\n", family);
	}

	return sockif;
}
