#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

#ifdef _WIN32
void displays_emojis_windows(void) {
    //  NOTE:   On a Windows system emojis can't be used with the unicode format,
    //          because this is out of range for wchar_t [0..65,535], thus an
    //          alternate way has to be used here, however, this may not be
    //          able to display on your Windows machine.

    //  using surrogate pair instead (=> expected: 😀)
    wchar_t emoji[] = {
        0xD83D,
        0xDE00,
        0
    };

    wprintf(L"%ls\n", emoji);

    //  using an another alternate way, IF possible to display
    const wchar_t *emojis[] = {
        L"😀",
        L"😂",
        L"🚀",
        L"🔥"
    };
    size_t nbr_emojis = sizeof(emojis) / sizeof(emojis[0]);

    for (size_t i = 0; i < nbr_emojis; i++)
        wprintf(L"%ls\n", emojis[i]);
    }
#endif

#ifndef _WIN32
void display_emojis_other_os(void) {
    wchar_t emojis[] = {L'\U0001F600', L'\U0001F680', L'\U0001F525'};   // smile, rocket, heart
    size_t nbr_emojis = sizeof(emojis) / sizeof(emojis[0]);

    for(size_t i = 0; i < nbr_emojis; i++) {
        wprintf(L"%u: %lc\n", i, emojis[i]);
    }
}
#endif

void show_greek_alphabet(void) {
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

    size_t nbr_greek_chars = sizeof(greek_alphabet) / sizeof(greek_alphabet[0]);

    for(size_t i = 0; i < nbr_greek_chars; i++) {
        wprintf(L"%2u: %lc\n", i+1, greek_alphabet[i]);
    }
}

int main(void) {
    setlocale(/*category: */ LC_ALL, /*locale: */ "");

    //  NOTE:   On a Windows system you might get a warning like:
    //          "warning: character not encodable in a single code unit"
    //
    //          Because on Windows wchar_t usually comes with an upper
    //          boundary of 65,535 whereas on an UNIX system this is often
    //          limited to 2,147,483,647.

    #ifdef _WIN32
    puts("WARNING: These samples below may unable to display or shows any garbage, because wchar_t has a lower limitation than on an another OS.");

    //  NOTE    If "_O_U16TEXT" may not be known, which should, then this expression must be
    //          redefined again with: #define _O_U16TEXT     0x20000
    _setmode(_fileno(stdout), _O_U16TEXT);

    displays_emojis_windows();
    #else
    display_emojis_other_os();
    #endif

    show_greek_alphabet();      //  NOTE: On Windows not every greek character is able to display

    return EXIT_SUCCESS;
}