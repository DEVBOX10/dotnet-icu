
/*
********************************************************************
* COPYRIGHT: 
* (C) Copyright Taligent, Inc., 1997
* (C) Copyright International Business Machines Corporation, 1997 - 1998
* Licensed Material - Program-Property of IBM - All Rights Reserved. 
* US Government Users Restricted Rights - Use, duplication, or disclosure 
* restricted by GSA ADP Schedule Contract with IBM Corp. 
*
********************************************************************
*/
 
#ifndef _NUMBERFORMATTEST_
#define _NUMBERFORMATTEST_
 
#include "unicode/utypes.h"
#include "caltztst.h"
class NumberFormat;
class DecimalFormat;

/**
 * Performs various in-depth test on NumberFormat
 **/
class NumberFormatTest: public CalendarTimeZoneTest {
    // IntlTest override
    void runIndexedTest( int32_t index, bool_t exec, char* &name, char* par );
public:
    /*
     * Test the handling of quotes
     **/
    virtual void TestQuotes(void);
    /**
     * Test patterns with exponential representation
     **/
    virtual void TestExponential(void);
    /**
     * Test handling of patterns with currency symbols
     **/
    virtual void TestCurrencySign(void);
    /**
     * Test different format patterns
     **/
    virtual void TestPatterns(void);
 
public: // package
    // internal utility routine
    static UnicodeString& escape(UnicodeString& s);
 
public:
    /**
     * Test localized currency patterns.
     */
    virtual void TestCurrency(void);
    /**
     * Do rudimentary testing of parsing.
     */
    virtual void TestParse(void);
    /**
     * Test proper rounding by the format method.
     */
    virtual void TestRounding487(void);

    // New tests for alphaWorks upgrade
    virtual void TestExponent(void);
    virtual void TestScientific(void);
    void expect(NumberFormat& fmt, const UnicodeString& str, int32_t n);
    void expect(NumberFormat& fmt, const Formattable& n,
                const UnicodeString& exp);
    void expect(NumberFormat* fmt, const Formattable& n,
                const UnicodeString& exp, UErrorCode);
    void TestPad(void);
    void TestPatterns2(void);
    void expectPad(DecimalFormat& fmt, const UnicodeString& pat,
                   int32_t pos);
    void expectPad(DecimalFormat& fmt, const UnicodeString& pat,
                   int32_t pos, int32_t width, UChar pad);
    void expectPat(DecimalFormat& fmt, const UnicodeString& exp);
    enum { ILLEGAL = -1 };

public: // package
    // internal subtest used by TestRounding487
    virtual void roundingTest(NumberFormat& nf, double x, int32_t maxFractionDigits, const char* expected);
};
 
#endif // _NUMBERFORMATTEST_
