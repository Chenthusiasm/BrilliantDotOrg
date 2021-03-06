/// Main file for problems solved on https://brilliant.org.


// === INCLUDES ================================================================

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// === DEFINES =================================================================


// === PRIVATE FUNCTIONS =======================================================

/// Print a 1-D array.
static void printArray(int* array, int length)
{
    printf("[ ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}


// === HELPER PROBLEMS =========================================================

void cryptogram(char const formula)
{

}


// === PROBLEMS ================================================================

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


// === THE LOST TIME ===========================================================

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


// === SUBTRACT THE SQUARES ====================================================

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


// === NUMBERS IN HEXAGON ======================================================

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


// === CONSECUTIVE SUMS ========================================================

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


// === RED OR GREEN ? ==========================================================

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


// === A BUS TRIP ==============================================================

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

// === POLYGONS IN A ROW =======================================================

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


// === HIDDEN TRIANGES =========================================================

/// Focusing on the two triangular numbers may help you solve this Grid Fill
/// puzzle.
/// How many solutions does the puzzle have?

///  a  b  c  6
///  d  e  f  9
///  g  h  i 12
///  0  j  0
///  9 10 11


static bool isHiddenTrianglesValid(int* val, int valLength)
{
    return (((val[0] + val[1] + val[2]) == 6) &&
            ((val[3] + val[4] + val[5]) == 9) &&
            ((val[6] + val[7] + val[8]) == 12) &&
            ((val[0] + val[3] + val[6]) == 9) &&
            ((val[1] + val[4] + val[7] + val[9]) == 10) &&
            ((val[2] + val[5] + val[8]) == 11));
}


static void hiddenTrianglesHelper(int* val, int valLength, int offset, int* in, int inLength)
{
    if (offset >= valLength)
    {
        if (isHiddenTrianglesValid(val, valLength))
            printArray(val, valLength);
    }
    else
    {
        for (val[offset] = 1; val[offset] < inLength; ++val[offset])
        {
            if (in[val[offset]] <= 0)
                continue;
            in[val[offset]]--;
            hiddenTrianglesHelper(val, valLength, offset + 1, in, inLength);
            in[val[offset]]++;
        }
    }
}


void hiddenTriangles(void)
{
    int in[] = { 0, 1, 2, 3, 4 };
    int inLength = sizeof(in) / sizeof(int);
    int val[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int valLength = sizeof(val) / sizeof(int);

    hiddenTrianglesHelper(val, valLength, 0, in, inLength);
    printf("finished hiddenTriangles\n");
}


// === THIS CRYPTOGRAM RHYMES ==================================================

///       B L A
/// x       B A
/// -----------
///   A L P H A
/// Given that every letter corresponds to a different digit, what is the value
/// of H?
/// Hint: If you narrow down the values of A and B, you can get to the solution
/// by analyzing the various cases.


bool thisCryptogramRhymesCheck(int* val, int valLength)
{
    int a = val[0];
    int b = val[1];
    int h = val[2];
    int l = val[3];
    int p = val[4];

    int bla = 100 * b + 10 * l + a;
    int ba = 10 * b + a;
    int alpha = 10000 * a + 1000 * l + 100 * p + 10 * h + a;

    return ((bla * ba) == alpha);
}


void thisCryptogramRhymesSelector(int* val, int valLength, int offset, bool* used, int usedLength)
{
    if (offset >= valLength)
    {
        if (thisCryptogramRhymesCheck(val, valLength))
            printArray(val, valLength);
    }
    else
    {
        for (val[offset] = 0; val[offset] < usedLength; ++val[offset])
        {
            if (used[val[offset]])
                continue;
            used[val[offset]] = true;
            thisCryptogramRhymesSelector(val, valLength, offset + 1, used, usedLength);
            used[val[offset]] = false;
        }
    }
}

void thisCryptogramRhymes(void)
{
    bool used[] = { false, false, false, false, false, false, false, false, false, false };
    int usedLength = sizeof(used) / sizeof(bool);
    // [0]: A
    // [1]: B
    // [2]: H
    // [3]: L
    // [4]: P
    int val[] = { 0, 0, 0, 0, 0 };
    int valLength = sizeof(val) / sizeof(int);
    thisCryptogramRhymesSelector(val, valLength, 0, used, usedLength);
    printf("finished thisCryptogramRhymes");
}


// === WHAT IS IMPOSSIBLE ======================================================

/// Which of the following numbers can't you get by changing some of the + to -?
/// 1 + 2 + 3 + 4 = 10


void whatIsImpossibleHelper(bool* isMinus, int isMinusLength, int offset)
{
    if (offset >= isMinusLength)
    {
        int n = 1;
        n += (isMinus[0] ? (-1) : (1)) * 2;
        n += (isMinus[1] ? (-1) : (1)) * 3;
        n += (isMinus[2] ? (-1) : (1)) * 4;
        printf("1 %c 2 %c 3 %c 4 = %d\n",
            isMinus[0] ? '-' : '+',
            isMinus[1] ? '-' : '+',
            isMinus[2] ? '-' : '+',
            n
        );
    }
    else
    {
        isMinus[offset] = false;
        whatIsImpossibleHelper(isMinus, isMinusLength, offset + 1);
        isMinus[offset] = true;
        whatIsImpossibleHelper(isMinus, isMinusLength, offset + 1);
    }
}


void whatIsImpossible(void)
{
    bool isMinus[] = { false, false, false };
    int isMinusLength = sizeof(isMinus) / sizeof(bool);
    whatIsImpossibleHelper(isMinus, isMinusLength, 0);
}


// === SENIOR PRANK ============================================================

/// At a university, the portraits of its 5050 presidents line a hallway of the
/// student center. Every year, 5050 students pull the following prank:
/// 1.  The first student covers every portrait in yellow paint.
/// 2.  The second student paints over every second portrait in blue paint.
/// 3.  The third student goes to every third portrait and paints over it in the
///     opposite color — the yellow portraits get painted blue and the blue
///     portraits get painted yellow.
/// 4.  The fourth student goes to every fourth portrait and paints over it in
///     the opposite color.
/// 5.  This pattern continues through the fiftieth student.
/// After all 5050 students have finished, which of the following presidents'
/// portraits is painted yellow?

#define SP_NUM_PORTRAITS                (50U)
#define SP_YELLOW                       ('Y')
#define SP_BLUE                         ('B')

void seniorPrank(void)
{
    char portraits[SP_NUM_PORTRAITS];

    // First student colors everything yello.
    for (int i = 0; i < SP_NUM_PORTRAITS; ++i)
        portraits[i] = SP_YELLOW;

    for (int i = 1; i < SP_NUM_PORTRAITS; ++i)
    {
        for (int j = 0; j < SP_NUM_PORTRAITS; ++j)
        {
            int s = i + 1;
            int p = j + 1;
            if ((p % s) == 0)
            {
                if (portraits[j] == SP_YELLOW)
                    portraits[j] = SP_BLUE;
                else if (portraits[j] == SP_BLUE)
                    portraits[j] = SP_YELLOW;
            }

            //if (j == 35)
            //    printf("[%d:%d]: %c\n", s, p, portraits[j]);
        }
    }
    for (int i = 0; i < SP_NUM_PORTRAITS; ++i)
        printf("[%d]: %c\n", i + 1, portraits[i]);
}


// === THE MYSTERIOUS AGE ======================================================

void mysteriousAge(void)
{
    printf("myseriousAge:\n");
    for (int a = 0; a < 100; ++a)
    {
        int b = (4 * ((a / 10) * (a % 10))) + 1;
        //printf("a = %d, b = %d\n", a, b);
        if (a == b)
            printf("age = %d\n", a);
    }
}


// === MAKING NECKLACES ========================================================

#define MK_SIZE                 (6u)
#define MK_PERM_COUNT           (64u)

bool checkNecklace(bool beads[], int beadsLength, bool isSet[], int isSetLength)
{
    bool status = true;

    for (int i = 0; i < beadsLength; ++i)
    {
        int total = 0;
        for (int j = 0; j < beadsLength; ++j)
        {
            int offset = (i + j) % beadsLength;
            int v = (beads[offset]) ? (1) : (0);
            total += v << j;
        }
        if (isSet[total])
            status = false;
        isSet[total] = true;
    }

    return status;
}


int makingNecklacesHelper(bool beads[], int beadsLength, int offset, bool isSet[], int isSetLength)
{
    if (offset >= beadsLength)
    {
        if (checkNecklace(beads, beadsLength, isSet, isSetLength))
        {
            printf("[ ");
            for (int i = 0; i < beadsLength; ++i)
            {
                printf("%d, ", beads[i]);
            }
            printf("]\n");
            return 1;
        }
        else
            return 0;
    }
    else
    {
        beads[offset] = false;
        int a = makingNecklacesHelper(beads, beadsLength, offset + 1, isSet, isSetLength);
        beads[offset] = true;
        int b = makingNecklacesHelper(beads, beadsLength, offset + 1, isSet, isSetLength);
        beads[offset] = false;
        return a + b;
    }
}


void makingNecklaces(void)
{
    bool isGold[MK_SIZE] = { false };
    bool isSet[MK_PERM_COUNT] = { false };

    memset(isGold, 0, sizeof(isGold));
    memset(isSet, 0, sizeof(isSet));

    int count = makingNecklacesHelper(isGold, MK_SIZE, 0, isSet, MK_PERM_COUNT);
    printf("makingNecklaces = %d\n", count);
}


// === CHERRY PRODUCTION =======================================================
///     A P P L E
/// +     P E A R
/// -------------
///   C H E R R Y
/// If every letter corresponds to a different digit and E=5,E=5, what is Y?

/// 0 1 2 3 4 5 6
/// A C H L P R Y
/// E = 5

/// A: [0]
/// P: [4]
/// P: [4]
/// L: [3]
/// E: 5

/// P: [4]
/// E: 5
/// A: [0]
/// R: [5]

/// C: [1]
/// H: [2]
/// E: 5
/// R: [5]
/// R: [5]
/// Y: [6]

void checkCherryProduction(int vals[], size_t length)
{
    int const e = 5;
    int const iA = 0;
    int const iC = 1;
    int const iH = 2;
    int const iL = 3;
    int const iP = 4;
    int const iR = 5;
    int const iY = 6;

    bool status = true;

    //printArray(vals, length);

    for (size_t i = 0; status && (i < length); ++i)
    {
        if (vals[i] == e)
            status = false;
        for (size_t j = i + 1; status && (j < length); ++j)
        {
            status = status && (vals[i] != vals[j]);
        }
    }
    if (status)
    {
        int apple = 10000 * vals[iA] +
                     1000 * vals[iP] +
                      100 * vals[iP] +
                       10 * vals[iL] +
                        1 * e;

        int pear = 1000 * vals[iP] +
                    100 * e +
                     10 * vals[iA] +
                      1 * vals[iR];

        int cherry = 100000 * vals[iC] +
                      10000 * vals[iH] +
                       1000 * e +
                        100 * vals[iR] +
                         10 * vals[iR] +
                          1 * vals[iY];
        //printf("\tapple + pear = cherry    ->    %d + %d = %d\n", apple, pear, cherry);
        status = status && (cherry == (apple + pear));
    }

    if (status)
    {
        printf("A = %d\n", vals[iA]);
        printf("C = %d\n", vals[iC]);
        printf("E = %d\n", e);
        printf("H = %d\n", vals[iH]);
        printf("L = %d\n", vals[iL]);
        printf("P = %d\n", vals[iP]);
        printf("R = %d\n", vals[iR]);
        printf("Y = %d\n", vals[iY]);
    }
}


void cherryProductionHelper(int vals[], size_t length, int offset)
{
    if (offset >= length)
        checkCherryProduction(vals, length);
    else
    {
        for (size_t i = 0; i < 10; ++i)
        {
            vals[offset] = i;
            cherryProductionHelper(vals, length, offset + 1);
        }    
    }
}

#define CP_LENGTH                       (7u)

void cherryProduction(void)
{
    int vals[CP_LENGTH] = { 0 };
    printf("cherryProduction:\n");
    cherryProductionHelper(vals, CP_LENGTH, 0);
}


// === OPPORTUNITIES IN 2021 ===================================================

void oppChecker(int* year, size_t yearLength)
{
    if (year[0] != 0)
        printArray(year, yearLength);
}


void oppHelper(int* year, size_t yearLength, size_t offset, int* input, size_t inputLength)
{
    if (offset >= yearLength)
        oppChecker(year, yearLength);
    else
    {
        for (size_t i = 0; i < inputLength; ++i)
        {
            if (input[i] > 0)
            {
                input[i]--;
                year[offset] = i;
                oppHelper(year, yearLength, offset + 1, input, inputLength);
                input[i]++;
            }
        }
    }
}

#define OPP_YEAR_LENGTH                 (4u)
#define OPP_INPUT_LENGTH                (3u)
void opp2021(void)
{
    int year[OPP_YEAR_LENGTH] = { 0 };
    int input[OPP_INPUT_LENGTH] = { 1, 1, 2 };
    oppHelper(year, OPP_YEAR_LENGTH, 0, input, OPP_INPUT_LENGTH);
}


// === PLUS OR NONPLUSSED ======================================================

/// Within the outlined square below, 55 smaller, shaded squares are arranged in
/// a plus sign. We create a fractal pattern by recursively repeating this
/// procedure:
/// For each shaded square that has exactly one of its sides bordering another
/// shaded region, replace it with a scaled-down version of the original plus
/// sign.
/// After infinitely many iterations, what fraction of the outlined square's
/// area is shaded?

static double plusHelper(int n, double length)
{
    if (n == 0)
        return 0.0;
    else
    {
        double area = 2 * (length / 3) * (length / 3);
        area += 3 * plusHelper(n - 1, length / 3);
        return area;
    }
}


static void plusFractal(void)
{
    int n = 30;
    double length = (1.0 / 3.0);
    double area = length * length;
    area += 4.0 * plusHelper(n, length);
    printf("plus: n = %d, area = %f\n", n, area);
}


// === RANDOM ROBOT ROAMING ====================================================

/// 2/20/2021
/// The robot starts on the center dot of the grid, makes four moves of one unit
/// with each move in a randomly selected direction (up, down, left, or right),
/// and then stops. The robot does not move diagonally.
/// Which region is most likely to contain the dot the robot stops on?
/// a. The inner red square
/// b. The blue V region
/// c. The outer orange region

#define RRR_COL                         (9u)
#define RRR_ROW                         (9u)
#define O                               (0u)
#define R                               (1u)
#define B                               (2u)
#define Y                               (3u)

static uint8_t const RRRTable[RRR_ROW][RRR_COL] =
{
    { O, O, O, O, Y, O, O, O, O },
    { O, O, O, Y, Y, Y, O, O, O },
    { O, O, Y, Y, R, Y, Y, O, O },
    { O, Y, Y, R, R, R, Y, Y, O },
    { Y, Y, B, B, R, B, B, Y, Y },
    { O, Y, Y, B, B, B, Y, Y, O },
    { O, O, Y, Y, B, Y, Y, O, O },
    { O, O, O, Y, Y, Y, O, O, O },
    { O, O, O, O, Y, O, O, O, O },
};

static int rrrTally[] = { 0, 0, 0, 0 };

static void randomRobotRoamingHelper(int step, int x, int y)
{
    if (step <= 0)
        rrrTally[RRRTable[y][x]]++;
    else
    {
        randomRobotRoamingHelper(step - 1, x - 1, y);
        randomRobotRoamingHelper(step - 1, x + 1, y);
        randomRobotRoamingHelper(step - 1, x, y - 1);
        randomRobotRoamingHelper(step - 1, x, y + 1);
    }
}

static void randomRobotRoaming(void)
{
    randomRobotRoamingHelper(4, RRR_COL/2, RRR_ROW/2);
    printf("randomrobotRoaming: 0=%d r=%d, b=%d, y=%d t=%d\n",
        rrrTally[O], rrrTally[R], rrrTally[B], rrrTally[Y],
        rrrTally[O] + rrrTally[R] + rrrTally[B] + rrrTally[Y]);
}


#undef RRR_COL
#undef RRR_ROW
#undef O
#undef R
#undef B
#undef Y


// === THE POWER OF MATH =======================================================

/// 3/1/2021:
/// (M + A + T + H)^4 = MATH
/// Every letter corresponds to a different digit. What is M + A + T + H?


static void powerOfMathChecker(int vals[], int size)
{
    int mathAdd = vals[0] + vals[1] + vals[2] + vals[3];
    int mathPower4 = mathAdd * mathAdd * mathAdd * mathAdd;
    int math = (vals[0] * 1000) + (vals[1] * 100) + (vals[2] * 10) + vals[3];
    bool status = (math == mathPower4);

    if (status)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
                status = status && (vals[i] != vals[j]);
        }
    }

    if (status)
        printf("\tM = %d, A = %d, T = %d, H = %d; M + A + T + H = %d\n",
            vals[0], vals[1], vals[2], vals[3], mathAdd);
}


static void powerOfMathHelper(int offset, int vals[], int size)
{
    if (offset >= size)
        powerOfMathChecker(vals, size);
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            vals[offset] = i;
            powerOfMathHelper(offset + 1, vals, size);
        }
    }    
}


static void powerOfMath(void)
{
    int math[] = { 0, 0, 0, 0 };
    printf("M + A + T + H)^4 = MATH\n");
    powerOfMathHelper(0, math, sizeof(math)/sizeof(int));
}


// === HOW CAN YOU WRITE IT ====================================================

/// 2021-03-08
/// It is possible to write the number 2021 as a difference of two squares:
/// 2021 = 1011^2 - 1010^2.
/// Is there any other way to write 20212021 as a difference of two squares?
/// Note: We are looking for a difference of squares of positive integers.
/// Squares of negative numbers and non-integers don't count!

static void howCanYouWriteIt(void)
{
    static int const v = 2021;
    for (int x = 1; x < (v + 1); ++x)
    {
        for (int y = 1; y < x; ++y)
        {
            if ((x*x - y*y) == v)
                printf("%d^2 - %d^2 = %d\n", x, y, v);
        }
    }
}


// === PRIME TILES AND SUMS ====================================================

bool isPrime(int n)
{
    bool result = true;
    for (int i = 2; i <= n/2; ++i)
    {
        if ((n % i) == 0)
        {
            result = false;
            break;
        }
        if ((n / i) < i)
            break;
    }
    return result;
}


static void primeTilesAndSums(void)
{
    uint8_t const in[] = { 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < sizeof(in); ++i)
    {
        for (int j = i + 1; j < sizeof(in); ++j)
        {
            for (int k = j + 1; k < sizeof(in); ++k)
            {
                int sum0 = (int)in[i] + (int)in[j] + (int)in[k];
                if (!isPrime(sum0))
                    continue;
                for (int x = 0; x < sizeof(in); ++x)
                {
                    if ((x ==i) || (x == j) || (x == k))
                        continue;
                    for (int y = x + 1; y < sizeof(in); ++y)
                    {
                        if ((y ==i) || (y == j) || (y == k))
                            continue;
                        for (int z = y + 1; z < sizeof(in); ++z)
                        {
                            if ((z ==i) || (z == j) || (z == k))
                                continue;
                            int sum1 = (int)in[x] + (int)in[y] + (int)in[z];
                            if (sum0 == sum1)
                                printf("%d + %d + %d = %d ;  %d = %d + %d = %d\n", in[i], in[j], in[k], sum0, in[x], in[y], in[z], sum1);
                        }
                    }
                }
            }
        }
    }
}


// === AREA IN-BETWEEN =========================================================

/// 3/30/2021
/// Initially, a square with side length 22 has a circle inscribed, with the
/// area between the circle's and square's perimeters shaded:\\[1em]

/// Suppose that we recursively inscribe a scaled-down version of this figure in
/// the innermost circle. The following are the first two iterations of the
/// procedure:\\[1em]

/// If this procedure is repeated infinitely many times, what is the total
/// shaded area?

double areaInBetweenHelper(int iteration, double length)
{
    if (iteration == 0)
        return 0;
    else
    {
        double halfLength = length / 2.0;
        double area = (length * length) - (M_PI * halfLength * halfLength);
        return area + areaInBetweenHelper(iteration - 1, length / sqrt(2.0));
    }
}

void areaInBetween(void)
{
    double area = areaInBetweenHelper(10000, 2.0);
    printf("AREA IN-BETWEEN: a = %f\r\n", area);
}


// === IN FOR THE WIN ==========================================================

/// 4/2/2021
/// Each letter represents a different digit. What is WIN?
///
///   I N
/// x I N
/// -----
/// W I N

// === STACK OF CIRCLES ========================================================

static double stackOfCirclesHelper(int i, double r)
{
    if (i == 0)
        return 0.0;
    else
    {
        double a = M_PI * r * r;
        r = r * 0.75;
        a -= M_PI * r * r;
        r = r * 0.75;
        a += stackOfCirclesHelper(i - 1, r);
        return a;
    }
}


static void stackOfCircles(void)
{
    int i = 1000;
    double yellow = stackOfCirclesHelper(i, 1.0);
    double blue = stackOfCirclesHelper(i, 0.75);
    printf("Stack of Circles [%i]: y = %f, b = %f\r\n", i, yellow, blue);
}


// === THE SMALLEST Z ==========================================================

/// 5/23/2021
/// Initially:
///     x = -1
///     y = 0
///     z = 1
/// Instructions:
///     x = x + y
///     y = x - y
///     z = x * y

static void smallestZStepA(int* x, int* y, int* z)
{
    *x = *x + *y;
}

static void smallestZStepB(int* x, int* y, int* z)
{
    *y = *x - *y;
}

static void smallestZStepC(int* x, int* y, int* z)
{
    *z = *x * *y;
}

static void smallestZInit(int* x, int* y, int* z)
{
    *x = -1;
    *y = 0;
    *z = 1;
}

static void smallestZPrint(int const* x, int const* y, int const* z)
{
    printf("x = %d  y = %d  z = %d\r\n", *x, *y, *z);
}

typedef void (*smallestZFunction)(int*, int*, int*);

static void smallestZ(void)
{
    smallestZFunction const functions[] = { smallestZStepA, smallestZStepB, smallestZStepC };
    int const functionsCount = sizeof(functions) / sizeof(smallestZFunction);

    int x;
    int y;
    int z;

    smallestZInit(&x, &y, &z);
    smallestZPrint(&x, &y, &z);

    smallestZInit(&x, &y, &z);
    functions[0](&x, &y, &z);
    functions[1](&x, &y, &z);
    functions[2](&x, &y, &z);
    smallestZPrint(&x, &y, &z);

    smallestZInit(&x, &y, &z);
    functions[0](&x, &y, &z);
    functions[2](&x, &y, &z);
    functions[1](&x, &y, &z);
    smallestZPrint(&x, &y, &z);

    smallestZInit(&x, &y, &z);
    functions[1](&x, &y, &z);
    functions[0](&x, &y, &z);
    functions[2](&x, &y, &z);
    smallestZPrint(&x, &y, &z);

    smallestZInit(&x, &y, &z);
    functions[1](&x, &y, &z);
    functions[2](&x, &y, &z);
    functions[0](&x, &y, &z);
    smallestZPrint(&x, &y, &z);

    smallestZInit(&x, &y, &z);
    functions[2](&x, &y, &z);
    functions[0](&x, &y, &z);
    functions[1](&x, &y, &z);
    smallestZPrint(&x, &y, &z);

    smallestZInit(&x, &y, &z);
    functions[2](&x, &y, &z);
    functions[1](&x, &y, &z);
    functions[0](&x, &y, &z);
    smallestZPrint(&x, &y, &z);
}

// === MAIN ====================================================================

int main(void)
{
    smallestZ();
    return 0;
}

