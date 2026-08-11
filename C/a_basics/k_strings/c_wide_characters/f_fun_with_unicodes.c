#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>

HANDLE h;
DWORD written;
#endif

void display_emojis(void) {
    /////
    //  single emoji
    /////

    //  displays a grinning smiley
    wchar_t emoji[] = {
        0xD83D,
        0xDE00,
        0
    };

    /////
    //  array of emoji symbols
    /////
    const wchar_t *emojis_0[] = {
        L"😀",
        L"😂",
        L"🚀",
        L"🔥"
    };

    size_t nbr_emojis_0 = sizeof(emojis_0) / sizeof(emojis_0[0]);

    /////
    //  array of emoji codes
    /////
    wchar_t emojis_1[] = {
        L"\U0001F600"
        L"\U0001F680"
        L"\U0001F525"
    };  // smile, rocket, fire

    #ifdef _WIN32
        h = GetStdHandle(STD_OUTPUT_HANDLE);

        WriteConsoleW(                                                      //  single grinning smiley
            h,
            emoji,
            (DWORD)(sizeof(emoji) / sizeof(wchar_t) - 1),
            &written,
            NULL
        );
        printf("\n");

        for (size_t i = 0; i < nbr_emojis_0; i++) {                         //  grinning, laughing, rocket, fire
            WriteConsoleW(
                h,
                emojis_0[i],
                (DWORD)wcslen(emojis_0[i]),
                &written,
                NULL
            );
        }
        printf("\n");

        WriteConsoleW(                                                      //  grinning, rocket, fire
            h,
            emojis_1,
            (DWORD)wcslen(emojis_1),
            &written,
            NULL
        );
        printf("\n");
    #else
        wprintf(L"%ls\n", emoji);                                           //  single grinning smiley (may not be able to display on each system)

        for (size_t i = 0; i < nbr_emojis_0; i++) {                         //  grinning, laughing, rocket, fire
            wprintf(L"%ls", emojis_0[i]);
        }
        printf("\n");

        size_t nbr_emojis_1 = sizeof(emojis_1) / sizeof(emojis_1[0]);       //  grinning, rocket, fire

        for(size_t i = 0; i < nbr_emojis_1; i++) {
            wprintf(L"%lc\n", emojis_1[i]);
        }
        printf("\n");
    #endif
}

void display_greek_alphabet(void) {
    wchar_t greek_alphabet[] = {
        L'\u03B1', // α Alpha
        L'\u03B2', // β Beta
        L'\u03B3', // γ Gamma
        L'\u03B4', // δ Delta
        L'\u03B5', // ε Epsilon
        L'\u03B6', // ζ Zeta
        L'\u03B7', // η Eta
        L'\u03B8', // θ Theta
        L'\u03B9', // ι Iota
        L'\u03BA', // κ Kappa
        L'\u03BB', // λ Lambda
        L'\u03BC', // μ Mu
        L'\u03BD', // ν Nu
        L'\u03BE', // ξ Xi
        L'\u03BF', // ο Omicron
        L'\u03C0', // π Pi
        L'\u03C1', // ρ Rho
        L'\u03C3', // σ Sigma
        L'\u03C4', // τ Tau
        L'\u03C5', // υ Upsilon
        L'\u03C6', // φ Phi
        L'\u03C7', // χ Chi
        L'\u03C8', // ψ Psi
        L'\u03C9', // ω Omega
        L'\u0391', // Α Alpha
        L'\u0392', // Β Beta
        L'\u0393', // Γ Gamma
        L'\u0394', // Δ Delta
        L'\u0395', // Ε Epsilon
        L'\u0396', // Ζ Zeta
        L'\u0397', // Η Eta
        L'\u0398', // Θ Theta
        L'\u0399', // Ι Iota
        L'\u039A', // Κ Kappa
        L'\u039B', // Λ Lambda
        L'\u039C', // Μ Mu
        L'\u039D', // Ν Nu
        L'\u039E', // Ξ Xi
        L'\u039F', // Ο Omicron
        L'\u03A0', // Π Pi
        L'\u03A1', // Ρ Rho
        L'\u03A3', // Σ Sigma
        L'\u03A4', // Τ Tau
        L'\u03A5', // Υ Upsilon
        L'\u03A6', // Φ Phi
        L'\u03A7', // Χ Chi
        L'\u03A8', // Ψ Psi
        L'\u03A9'  // Ω Omega
    };

    #ifdef _WIN32
        WriteConsoleW(
            h,
            greek_alphabet,
            (DWORD)(sizeof(greek_alphabet) / sizeof(wchar_t) - 1),
            &written,
            NULL
        );
    #else
        size_t nbr_greek_chars = sizeof(greek_alphabet) / sizeof(greek_alphabet[0]);

        for(size_t i = 0; i < nbr_greek_chars; i++) {
            wprintf(L"%lc", greek_alphabet[i]);
        }
    #endif

    puts("");               //  just a mark for a new line
}

int main(void) {
    //  NOTE:   On a Windows system emojis, special unicode character codes
    //          won't work with wchar_t, as well as, wprintf.
    //
    //          Here, the Windows API is required to handle this issue,
    //          because wchar_t has a range of 0..65535 (Windows), whereas
    //          on an UNIX system wchar_t comes with a range of
    //          0..2,147,483,647.

    //  more required for UNIX systems (Windows doesn't need this)
    setlocale(/*category: */ LC_ALL, /*locale: */ "");

    display_emojis();
    display_greek_alphabet();

    return EXIT_SUCCESS;
}