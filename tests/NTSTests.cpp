/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** NTSTests
*/

#include <istream>
#include "NTS.hpp"
#include "Tests.hpp"
#include <criterion/redirect.h>

void redirect()
{
    cr_redirect_stdin();
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nts, basic, .init = redirect)
{
    {
        const char *str = "display\n" \
                          "in_01=1\n" \
                          "in_02=1\n" \
                          "in_05=1\n" \
                          "in_06=0\n" \
                          "in_12=1\n" \
                          "in_13=U\n" \
                          "simulate\n" \
                          "display\n" \
                          "in_05=U\n" \
                          "display\n" \
                          "simulate\n" \
                          "display\n" \
                          "exit\n";
        fprintf(cr_get_redirected_stdin(), str);

        NTS nts{"./tests/nts/4081_and.nts"};

        cr_assert_eq(nts.run(), 0);
    }

    const char *out =
        "> " \
        "tick: 0\n" \
        "input(s):\n" \
        "  in_01: U\n" \
        "  in_02: U\n" \
        "  in_05: U\n" \
        "  in_06: U\n" \
        "  in_08: U\n" \
        "  in_09: U\n" \
        "  in_12: U\n" \
        "  in_13: U\n" \
        "output(s):\n" \
        "  out_03: U\n" \
        "  out_04: U\n" \
        "  out_10: U\n" \
        "  out_11: U\n" \

        "> > > > > > > > " \
        "tick: 1\n" \
        "input(s):\n" \
        "  in_01: 1\n" \
        "  in_02: 1\n" \
        "  in_05: 1\n" \
        "  in_06: 0\n" \
        "  in_08: U\n" \
        "  in_09: U\n" \
        "  in_12: 1\n" \
        "  in_13: U\n" \
        "output(s):\n" \
        "  out_03: 1\n" \
        "  out_04: 0\n" \
        "  out_10: U\n" \
        "  out_11: U\n" \

        "> > " \
        "tick: 1\n" \
        "input(s):\n" \
        "  in_01: 1\n" \
        "  in_02: 1\n" \
        "  in_05: 1\n" \
        "  in_06: 0\n" \
        "  in_08: U\n" \
        "  in_09: U\n" \
        "  in_12: 1\n" \
        "  in_13: U\n" \
        "output(s):\n" \
        "  out_03: 1\n" \
        "  out_04: 0\n" \
        "  out_10: U\n" \
        "  out_11: U\n" \

        "> > " \
        "tick: 2\n" \
        "input(s):\n" \
        "  in_01: 1\n" \
        "  in_02: 1\n" \
        "  in_05: U\n" \
        "  in_06: 0\n" \
        "  in_08: U\n" \
        "  in_09: U\n" \
        "  in_12: 1\n" \
        "  in_13: U\n" \
        "output(s):\n" \
        "  out_03: 1\n" \
        "  out_04: 0\n" \
        "  out_10: U\n" \
        "  out_11: U\n" \
        "> ";

    cr_assert_stdout_eq_str(out);
}

Test(nts, invalid_cmd, .init = redirect)
{
    {
        const char *str = "lol\n" \
                          "in_a=1\n" \
                          "in_02=1\n" \
                          "in_05=1\n" \
                          "in_06=0\n" \
                          "in_12=1\n" \
                          "in_13=U\n" \
                          "simulate\n" \
                          "display\n" \
                          "in_05=U\n" \
                          "display\n" \
                          "simulate\n" \
                          "display\n" \
                          "exit\n";
        fprintf(cr_get_redirected_stdin(), str);

        try {
            NTS nts{"./tests/nts/4081_and.nts"};

            nts.run();
            cr_assert(false);
        } catch(NtsError &e) {
            cr_assert(true);
        }
    }
}

Test(nts, invalid_input, .init = redirect)
{
    {
        const char *str = "display\n" \
                          "in_a=1\n" \
                          "in_02=1\n" \
                          "in_05=1\n" \
                          "in_06=0\n" \
                          "in_12=1\n" \
                          "in_13=U\n" \
                          "simulate\n" \
                          "display\n" \
                          "in_05=U\n" \
                          "display\n" \
                          "simulate\n" \
                          "display\n" \
                          "exit\n";
        fprintf(cr_get_redirected_stdin(), str);

        try {
            NTS nts{"./tests/nts/4081_and.nts"};

            nts.run();
            cr_assert(false);
        } catch(NtsError &e) {
            cr_assert(true);
        }
    }
}

Test(nts, invalid_file, .init = redirect)
{
    {
        const char *str = "display\n" \
                          "in_01=1\n" \
                          "in_02=1\n" \
                          "in_05=1\n" \
                          "in_06=0\n" \
                          "in_12=1\n" \
                          "in_13=U\n" \
                          "simulate\n" \
                          "display\n" \
                          "in_05=U\n" \
                          "display\n" \
                          "simulate\n" \
                          "display\n" \
                          "exit\n";
        fprintf(cr_get_redirected_stdin(), str);

        try {
            NTS nts{"./tests/nts/lololololololol.nts"};

            nts.run();
            cr_assert(false);
        } catch(NtsError &e) {
            cr_assert(true);
        }
    }
}
