/*
 * Copyright (c) 2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __XLOCALE_H_
#define __XLOCALE_H_

#include <sys/cdefs.h>

#ifndef _USE_EXTENDED_LOCALES_
#define _USE_EXTENDED_LOCALES_
#endif /* _USE_EXTENDED_LOCALES_ */

#include <_locale.h>
#include <__xlocale.h>

#define LC_ALL_MASK			(  LC_COLLATE_MASK \
					 | LC_CTYPE_MASK \
					 | LC_MESSAGES_MASK \
					 | LC_MONETARY_MASK \
					 | LC_NUMERIC_MASK \
					 | LC_TIME_MASK )
#define LC_COLLATE_MASK			(1 << 0)
#define LC_CTYPE_MASK			(1 << 1)
#define LC_MESSAGES_MASK		(1 << 2)
#define LC_MONETARY_MASK		(1 << 3)
#define LC_NUMERIC_MASK			(1 << 4)
#define LC_TIME_MASK			(1 << 5)

#define _LC_NUM_MASK			6
#define _LC_LAST_MASK			(1 << (_LC_NUM_MASK - 1))

#define LC_GLOBAL_LOCALE		((locale_t)-1)
#define LC_C_LOCALE				((locale_t)NULL)

#ifdef MB_CUR_MAX
#undef MB_CUR_MAX
#define MB_CUR_MAX			(___mb_cur_max())
#ifndef MB_CUR_MAX_L
#define MB_CUR_MAX_L(x)			(___mb_cur_max_l(x))
#endif /* !MB_CUR_MAX_L */
#endif /* MB_CUR_MAX */

__BEGIN_DECLS
extern const locale_t _c_locale;

locale_t	duplocale(locale_t);
int		freelocale(locale_t);
struct lconv *	localeconv_l(locale_t);
locale_t	newlocale(int, __const char *, locale_t);
__const char *	querylocale(int, locale_t);
locale_t	uselocale(locale_t);
__END_DECLS

#endif /* __XLOCALE_H_ */
