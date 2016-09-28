/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A'; /* 'a' - 'A' equals 32 */
    else
        return c;
}
