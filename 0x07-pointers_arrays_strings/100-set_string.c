/**
 * set_string - Sets the value of a pointer to a char.
 * @s: A pointer to a pointer to char.
 * @to: A pointer to a char to set the value to.
 */
void set_string(char **s, char *to)
{
    *s = to;
}
