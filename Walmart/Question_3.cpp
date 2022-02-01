public bool WinnerOfGame(string colors)
{
    return CountPossibleMoves(colors, 'A') > CountPossibleMoves(colors, 'B');
}

public int CountPossibleMoves(string colors, char color)
{
    int retVal = 0;
    int countConsecutive = 0;

    for (int i = 0; i < colors.Length; i++)
    {
        if (colors[i] == color && (i > 0 && colors[i] == colors[i - 1]))
        {
            countConsecutive++;
            if (countConsecutive >= 3)
            {
                retVal++;
            }
        }
        else if (colors[i] == color)
        {
            countConsecutive = 1;
        }
        else
        {
            countConsecutive = 0;
        }
    }

    return retVal;
}
