void reverseString(char *s, int sSize)
{
    int n = sSize;
    char v[sSize + 1];
    int j = 0;

    while (n > 0)
    {
        v[j++] = s[--n];
    }
    v[j] = '\0';
    j = 0;
    while (v[j] != '\0')
    {
        s[j] = v[j];
        j++;
    }
}