/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of attributes.xs. Do not edit this file, edit attributes.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "attributes.xs"
/*    xsutils.c
 *
 *    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008
 *    by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 */

/*
 * 'Perilous to us all are the devices of an art deeper than we possess
 *  ourselves.'                                            --Gandalf
 *
 *     [p.597 of _The Lord of the Rings_, III/xi: "The Palantír"]
 */

#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/*
 * Contributed by Spider Boardman (spider.boardman@orb.nashua.nh.us).
 */

static int
modify_SV_attributes(pTHX_ SV *sv, SV **retlist, SV **attrlist, int numattrs)
{
    dVAR;
    SV *attr;
    int nret;

    for (nret = 0 ; numattrs && (attr = *attrlist++); numattrs--) {
	STRLEN len;
	const char *name = SvPV_const(attr, len);
	const bool negated = (*name == '-');

	if (negated) {
	    name++;
	    len--;
	}
	switch (SvTYPE(sv)) {
	case SVt_PVCV:
	    switch ((int)len) {
	    case 6:
		switch (name[3]) {
		case 'l':
		    if (memEQ(name, "lvalue", 6)) {
			bool warn =
			    !CvISXSUB(MUTABLE_CV(sv))
			 && CvROOT(MUTABLE_CV(sv))
			 && !CvLVALUE(MUTABLE_CV(sv)) != negated;
			if (negated)
			    CvFLAGS(MUTABLE_CV(sv)) &= ~CVf_LVALUE;
			else
			    CvFLAGS(MUTABLE_CV(sv)) |= CVf_LVALUE;
			if (warn) break;
			continue;
		    }
		    break;
		case 'h':
		    if (memEQ(name, "method", 6)) {
			if (negated)
			    CvFLAGS(MUTABLE_CV(sv)) &= ~CVf_METHOD;
			else
			    CvFLAGS(MUTABLE_CV(sv)) |= CVf_METHOD;
			continue;
		    }
		    break;
		}
		break;
	    }
	    break;
	default:
	    if (memEQs(name, 6, "shared")) {
			if (negated)
			    Perl_croak(aTHX_ "A variable may not be unshared");
			SvSHARE(sv);
                        continue;
	    }
	    break;
	}
	/* anything recognized had a 'continue' above */
	*retlist++ = attr;
	nret++;
    }

    return nret;
}

#line 103 "attributes.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 245 "attributes.c"

XS_EUPXS(XS_attributes__modify_attrs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_attributes__modify_attrs)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 98 "attributes.xs"
    SV *rv, *sv;
#line 257 "attributes.c"
#line 101 "attributes.xs"
    if (items < 1) {
usage:
	croak_xs_usage(cv, "@attributes");
    }

    rv = ST(0);
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);
    if (items > 1)
	XSRETURN(modify_SV_attributes(aTHX_ sv, &ST(0), &ST(1), items-1));

    XSRETURN(0);
#line 272 "attributes.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_attributes__fetch_attrs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_attributes__fetch_attrs)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 119 "attributes.xs"
    SV *rv, *sv;
    cv_flags_t cvflags;
#line 290 "attributes.c"
#line 122 "attributes.xs"
    if (items != 1) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);

    switch (SvTYPE(sv)) {
    case SVt_PVCV:
	cvflags = CvFLAGS((const CV *)sv);
	if (cvflags & CVf_LVALUE)
	    XPUSHs(newSVpvs_flags("lvalue", SVs_TEMP));
	if (cvflags & CVf_METHOD)
	    XPUSHs(newSVpvs_flags("method", SVs_TEMP));
	break;
    default:
	break;
    }

    PUTBACK;
#line 315 "attributes.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_attributes__guess_stash); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_attributes__guess_stash)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 150 "attributes.xs"
    SV *rv, *sv;
    dXSTARG;
#line 333 "attributes.c"
#line 153 "attributes.xs"
    if (items != 1) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    ST(0) = TARG;
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);

    if (SvOBJECT(sv))
	Perl_sv_sethek(aTHX_ TARG, HvNAME_HEK(SvSTASH(sv)));
#if 0	/* this was probably a bad idea */
    else if (SvPADMY(sv))
	sv_setsv(TARG, &PL_sv_no);	/* unblessed lexical */
#endif
    else {
	const HV *stash = NULL;
	switch (SvTYPE(sv)) {
	case SVt_PVCV:
	    if (CvGV(sv) && isGV(CvGV(sv)) && GvSTASH(CvGV(sv)))
		stash = GvSTASH(CvGV(sv));
	    else if (/* !CvANON(sv) && */ CvSTASH(sv))
		stash = CvSTASH(sv);
	    break;
	case SVt_PVGV:
	    if (isGV_with_GP(sv) && GvGP(sv) && GvESTASH(MUTABLE_GV(sv)))
		stash = GvESTASH(MUTABLE_GV(sv));
	    break;
	default:
	    break;
	}
	if (stash)
	    Perl_sv_sethek(aTHX_ TARG, HvNAME_HEK(stash));
    }

    SvSETMAGIC(TARG);
    XSRETURN(1);
#line 374 "attributes.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_attributes_reftype); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_attributes_reftype)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 197 "attributes.xs"
    SV *rv, *sv;
    dXSTARG;
#line 392 "attributes.c"
#line 200 "attributes.xs"
    if (items != 1) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    ST(0) = TARG;
    SvGETMAGIC(rv);
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);
    sv_setpv(TARG, sv_reftype(sv, 0));
    SvSETMAGIC(TARG);

    XSRETURN(1);
/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 *
 * ex: set ts=8 sts=4 sw=4 noet:
 */
#line 418 "attributes.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_attributes); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_attributes)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("attributes::_modify_attrs", XS_attributes__modify_attrs, file);
        (void)newXSproto_portable("attributes::_fetch_attrs", XS_attributes__fetch_attrs, file, "$");
        (void)newXSproto_portable("attributes::_guess_stash", XS_attributes__guess_stash, file, "$");
        (void)newXSproto_portable("attributes::reftype", XS_attributes_reftype, file, "$");
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

