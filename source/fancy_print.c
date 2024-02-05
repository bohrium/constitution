//char const* ansi_code(char c)
//{
//    switch (c) {
//    break; case 'B': return BLUE;
//    break; case 'C': return CYAN;
//    break; case 'G': return GREEN;
//    break; case 'M': return MAGENTA;
//    break; case 'R': return RED;
//    break; case 'W': return WHITE;
//    break; case 'Y': return YELLOW;
//    }
//    return NULL;
//}
//
//void colorprint(char const* str, ...)
//{
//    int len = 1;
//    for (char const* src=str; *src; ++src) {
//        switch (*src) {
//        break; case '@':    len += 8;
//        break; default:     len += 1;
//        }
//    }
//
//    char* colored = malloc(len);
//    char* dst = colored;
//    for (char const* src=str; *src; ++src) {
//        switch (*src) {
//        break; case '@':
//            ++src;
//            char const* a = ansi_code(*src);
//            /* TODO: what if a is NULL ? */
//            strcpy(dst, a);
//            dst += strlen(a);
//        break; default:
//            *dst = *src;
//            ++dst;
//        }
//    }
//    *dst = '\0';
//
//    // FILLIN : printf `colored`
//
//    free(colored);
//}


