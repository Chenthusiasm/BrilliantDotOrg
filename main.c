/// Main file for problems solved on https://brilliant.org.


//=== INCLUDES =================================================================

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//=== DEFINES ==================================================================

//=== PROBLEMS =================================================================

/// 11/14/2020:
///     L O V E
///     L O V E
///     L O V E
///     L O V E
///   + L O V E
///   ---------
///   S O L V E
///
/// L O V E * 5 = S O L V E

static void loveSolve(void)
{
    int const Upper = 9;
    int const Lower = 0;
    int const LowerNext = 1;
    for (int s = LowerNext; s <= Upper; ++s)
    {
        printf("\ts = %d\n", s);
        for (int l = LowerNext; l <= Upper; ++l)
        {
            if (l == s)
                continue;

            printf("\t\tl = %d\n", l);
            for (int o = Lower; o <= Upper; ++o)
            {
                if ((o == l) || (o == s))
                    continue;

                for (int v = Lower; v <= Upper; ++v)
                {
                    if ((v == o) || (v == l) || (v == s))
                        continue;
                        
                    for (int e = Lower; e <= Upper; ++e)
                    {
                        if ((e == v) || (e == o) || (e == l) || (e == s))
                            continue;

                        int love = l * 1000 + o * 100 + v * 10 + e;
                        int solve = s * 10000 + o * 1000 + l * 100 + v * 10 + e;

                        if ((love * 5) == solve)
                            printf("love = %d    solve = %d\n", love, solve);
                    }
                }
            }
        }
    }
}


//=== THE LOST TIME ============================================================

/// 11/28/2020:
/// English:    2nd, 4th
/// Geography:  1st, 5th
/// History:    3rd, 4th
/// Math:       1st, 2nd
/// Physics:    3rd, 5th

static bool isUnique(char const* sequence, size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        for (size_t j = i + 1; j < length; ++j)
        {
            if (sequence[i] == sequence[j])
                return false;
        }
    }
    return true;
}


static void lostTimeSolve(void)
{
    #define NUMBER_OF_CLASSES           (5u)
    #define NUMBER_OF_CANDIDATES        (2u)

    char const data[NUMBER_OF_CLASSES][NUMBER_OF_CANDIDATES] =
    {
        { 'g', 'm' },
        { 'e', 'm' },
        { 'h', 'p' },
        { 'e', 'h' },
        { 'g', 'p' }
    };

    for (size_t a = 0; a < NUMBER_OF_CANDIDATES; ++a)
    {
        char sequence[NUMBER_OF_CLASSES + 1] = { 0 };
        sequence[0] = data[0][a];
        for (size_t b = 0; b < NUMBER_OF_CANDIDATES; ++b)
        {
            sequence[1] = data[1][b];
            for (size_t c = 0; c < NUMBER_OF_CANDIDATES; ++c)
            {
                sequence[2] = data[2][c];
                for (size_t d = 0; d < NUMBER_OF_CANDIDATES; ++d)
                {
                    sequence[3] = data[3][d];
                    for (size_t e = 0; e < NUMBER_OF_CANDIDATES; ++e)
                    {
                        sequence[4] = data[4][e];
                        if (isUnique(sequence, NUMBER_OF_CLASSES))
                            printf("%s\n", sequence);
                    }
                }
            }
        }
    }
}


//=== SUBTRACT THE SQUARES =====================================================

/// 11/29/2020:
/// Initial: x = A
/// Initial: y = B
/// a.  x = x * y
/// b.  x = x - y
/// c.  y = 2 * y + 2


static void functionA(int* x, int* y)
{
    *x = (*x) * (*y);
}


static void functionB(int* x, int* y)
{
    *x = (*x) - (*y);
}


static void functionC(int* x, int* y)
{
    *y = (2 * (*y)) + (*x);
}


static void subtractTheSquares(void)
{
    void (*functions[])(int* x, int* y) = { &functionA, &functionB, &functionC };
    int length = sizeof(functions) / sizeof(void*);

    int const A = 13;
    int const B = 7;
    int x = A;
    int y = B;

    printf("x=%d, y=%d\n", x, y);
    printf("\tA^2=%d, B^2=%d; A^2-B^2=%d\n", x * x, y * y, x * x - y * y);

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (j == i)
                continue;

            for (int k = 0; k < length; ++k)
            {
                if ((k == i) || (k == j))
                    continue;

                x = A;
                y = B;

                functions[i](&x, &y);
                functions[j](&x, &y);
                functions[k](&x, &y);

                printf("i=%d, j=%d, k=%d; x=%d, y=%d\n", i, j, k, x, y);
            }
        }
    }
}


//=== NUMBERS IN HEXAGON =======================================================

/// In the following puzzle, dashed arrows denote addition, while solid arrows
/// denote multiplication. If all the circles must contain different positive
/// integers, which number will replace the question mark?

static int const HEXAGON_CENTER = 41;
static int const HEXAGON_F = 10;

static void processNumbers(int a, int b, int c, int d, int e)
{
    if (((a * e) == HEXAGON_F) &&
        ((a * c) == b) &&
        ((c * e) == d) &&
        ((a + b + c + d + e + HEXAGON_F) == HEXAGON_CENTER))
    {
        printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
    }
}


static void numbersInHexagon(void)
{
    int const MIN = 1;
    int const MAX = HEXAGON_CENTER - HEXAGON_F;

    for (int a = MIN; a < MAX; ++a)
    {
        for (int b = MIN; b < MAX; ++b)
        {
            if (b == a)
                continue;
            for (int c = MIN; c < MAX; ++c)
            {
                if ((c == b) || (c == a))
                    continue;
                for (int d = MIN; d < MAX; ++d)
                {
                    if ((d == c) || (d == b) || (d == a))
                        continue;
                    for (int e = MIN; e < MAX; ++e)
                    {
                        if ((e == d) || (e == c) || (e == b) || (e == a))
                            continue;
                        processNumbers(a, b, c, d, e);
                    }
                }
            }
        }
    }
}


//=== CONSECUTIVE SUMS =========================================================

/// _ _ X X _ _ 12
/// _ X _ _ X _ 13
/// X _ _ _ _ X 14
/// 4 5 6 7 8 9
///
/// 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6
///
/// a c X X i k 12
/// b X e g X l 13
/// X d f h j X 14
/// 4 5 6 7 8 9

#define CS_MIN              (1u)
#define CS_MAX              (6u)

static void consecutiveSums(void)
{
    int input[] = { 0, 2, 3, 2, 1, 3, 1 };
    for (int a = CS_MIN; a <= CS_MAX; ++a)
    {
        if (input[a] <= 0)
            continue;
        --input[a];
        for (int b = CS_MIN; b <= CS_MAX; ++b)
        {
            if ((input[b] <= 0) || ((a + b) != 4))
                continue;
            --input[b];
            for (int c = CS_MIN; c <= CS_MAX; ++c)
            {
                if (input[c] <= 0)
                    continue;
                --input[c];
                for (int d = CS_MIN; d <= CS_MAX; ++d)
                {
                    if ((input[d] <= 0) || ((c + d) != 5))
                        continue;
                    --input[d];
                    for (int e = CS_MIN; e <= CS_MAX; ++e)
                    {
                        if (input[e] <= 0)
                            continue;
                        --input[e];
                        for (int f = CS_MIN; f <= CS_MAX; ++f)
                        {
                            if ((input[f] <= 0) || ((e + f) != 6))
                                continue;
                            --input[f];
                            for (int g = CS_MIN; g <= CS_MAX; ++g)
                            {
                                if (input[g] <= 0)
                                    continue;
                                --input[g];
                                for (int h = CS_MIN; h <= CS_MAX; ++h)
                                {
                                    if ((input[h] <= 0) || ((g + h) != 7))
                                        continue;
                                    --input[h];
                                    for (int i = CS_MIN; i <= CS_MAX; ++i)
                                    {
                                        if (input[i] <= 0)
                                            continue;
                                        --input[i];
                                        for (int j = CS_MIN; j <= CS_MAX; ++j)
                                        {
                                            if ((input[j] <= 0) || ((i + j) != 8))
                                                continue;
                                            --input[j];
                                            for (int k = CS_MIN; k <= CS_MAX; ++k)
                                            {
                                                if (input[k] <= 0)
                                                    continue;
                                                --input[k];
                                                for (int l = CS_MIN; l <= CS_MAX; ++l)
                                                {
                                                    if ((input[l] <= 0) ||
                                                        ((k + l) != 9) ||
                                                        ((a + c + i + k) != 12) ||
                                                        ((b + e + g + l) != 13) ||
                                                        ((d + f + h + j) != 14))
                                                        continue;
                                                    --input[l];
                                                    printf("%d %d X X %d %d\n", a, c, i, k);
                                                    printf("%d X %d %d X %d\n", b, e, g, l);
                                                    printf("X %d %d %d %d X\n\n", d, f, h, j);
                                                    ++input[l];
                                                }
                                                ++input[k];
                                            }
                                            ++input[j];
                                        }
                                        ++input[i];
                                    }
                                    ++input[h];
                                }
                                ++input[g];
                            }
                            ++input[f];
                        }
                        ++input[e];
                    }
                    ++input[d];
                }
                ++input[c];
            }
            ++input[b];
        }
        ++input[a];
    }

}


//=== RED OR GREEN ? ===========================================================

static void redOrGreen(void)
{
    int red = 0;
    int green = 0;
    int blue = 0;
    for (int x = -10; x <= 10; ++x)
    {
        printf("x = %d: ", x);
        if (x > (6 - (x * x)))
        {
            if ((x * x) < (3 - (2 * x)))
            {
                printf("RED\n");
                ++red;
            }
            else
            {
                printf("GREEN\n");
                ++green;
            }
        }
        else
        {
            printf("BLUE\n");
            ++blue;
        }
    }

    printf("red = %d\ngreen = %d\nblue = %d\n", red, green, blue);
}


//=== A BUS TRIP ===============================================================

/// 1/1/2021
/// Kamila, Lily, Miriam, Naomi, and Odette are sitting on a bus right behind
/// one another, with no empty seats or other passengers in between.
/// 1. Naomi is closer to the front than Lily.
/// 2. Odette is sitting between Lily and Kamila.
/// 3. There are exactly two seats between Kamila and Miriam.
/// Which girl might be closest to the front of the bus?

#define ABT_SIZE                        (5u)

static bool aBusTripCondition1(int l, int n)
{
    return (n < l);
}


static bool aBusTripCondition2(int k, int l, int o)
{
    return ((((k + 1) == o) && ((o + 1) == l)) ||
        (((l + 1) == o) && ((o + 1) == k)));
}

static bool aBusTripCondition3(int k, int m)
{
    return (abs(k - m) == 3);
}

static void aBusTrip(void)
{
    for (int k = 0; k < ABT_SIZE; ++k)
    {
        for (int l = 0; l < ABT_SIZE; ++l)
        {
            if (l == k)
                continue;
            for (int m = 0; m < ABT_SIZE; ++m)
            {
                if ((m == k) || (m == l))
                    continue;
                for (int n = 0; n < ABT_SIZE; ++n)
                {
                    if ((n == k) || (n == l) || (n == m))
                        continue;
                    for (int o = 0; o < ABT_SIZE; ++o)
                    {
                        if ((o == k) || (o == l) || (o == m) || (o == n))
                            continue;

                        if (aBusTripCondition1(l, n) &&
                            aBusTripCondition2(k, l, o) &&
                            aBusTripCondition3(k, m))
                            printf("k=%d l=%d m=%d n=%d o=%d\n", k, l, m, n, o);
                    }
                }
            }
        }
    }
}

//=== POLYGONS IN A ROW ========================================================

/// There are xx regular polygons, all with nn sides of length 1, arranged in a
/// row as the triangles, squares, and pentagons are in the image below.
/// Which of the following expressions gives the perimeter of the resulting
/// shape?


int polygonsInARow(int x, int n)
{
    return (((n - 2) * x) + 2);
}


int polygonsInARowDebug(int x, int n)
{
    int perimeter = polygonsInARow(x, n);
    printf("polygonsInARow: x = %d, n = %d, perimeter = %d\n", x, n, perimeter);
}


void testPolygonsInARow(void)
{
    // 12 triangles
    polygonsInARowDebug(12, 3);

    // 7 squares
    polygonsInARowDebug(7, 4);

    // 6 pentagons
    polygonsInARowDebug(6, 5);
}


//=== MAIN =====================================================================

int main(void)
{
    testPolygonsInARow();
    return 0;
}

