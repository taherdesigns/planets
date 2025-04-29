#include <stdio.h>
#include <string.h>

#define MAX_PLANETS 100

struct atmosphere
{
    float oxygen;
    float carbonDioxide;
    float nitrogen;
};

struct planet
{
    char planetName[50];
    float distanceFromEarth;
    float gravity;
    struct atmosphere atmo;
    char habitable;
};

int main()
{
    int n, i, in;
    char nameKeyword[50];
    float oxyThreshold, co2Threshold;

    printf("Enter the number of planets: ");
    scanf("%d", &n);

    struct planet planets[MAX_PLANETS];

    // TODO: Implement input handling for planet details
    for (i = 0; i < n; i++)
    {
        // Prompt the user to enter details for each planet.
        printf("Enter Planet Name: ");
        // Write the scan statement for planet name
        // IMP: Assume that the planet name consists of just one word, and there are no spaces in the name.
        scanf("%s", planets[i].planetName);

        printf("Enter Distance from Earth (in light-years): ");
        // Write the scan statement for distance from Earth
        scanf("%f", &planets[i].distanceFromEarth);

        printf("Enter Planet Gravity (in terms of g): ");
        // Write the scan statement for gravity
        scanf("%f", &planets[i].gravity);

        printf("Enter Atmosphere Composition (Oxygen, Carbon Dioxide, Nitrogen) as percentages: ");
        // Write the scan statements for atmosphere composition
        scanf("%f", &planets[i].atmo.oxygen);
        scanf("%f", &planets[i].atmo.carbonDioxide);
        scanf("%f", &planets[i].atmo.nitrogen);

        // TODO: Check habitability and store result in 'habitable' field
        // Habitability condition: gravity between 0.8 and 1.2, oxygen between 18% and 25%

        // Uncomment and complete:
        if (planets[i].gravity >= 0.8 && planets[i].gravity <= 1.2 &&
            planets[i].atmo.oxygen >= 18 && planets[i].atmo.oxygen <= 25)
        {
            planets[i].habitable = 'Y';
        }
        else
        {
            planets[i].habitable = 'N';
        }
    }

    while (1)
    {
        // Provide the menu options
        printf("\nMENU\n1. Find and print all habitable planets\n2. Search by oxygen and carbon dioxide levels\n3. Search by keyword in planet names\n4. Exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            // TODO: Sort planets by distance using Selection Sort
            printf("Habitable planets (sorted by distance from Earth):\n");
            // Write sorting code and then print habitable planets in ascending order of distance
            // Format: printf("%s - %.2f light-years\n", planet_name, distance);

            for (int x = 0; x < n - 1; x++)
            {
                int minIndex = x;
                for (int y = x + 1; y < n; y++)
                {
                    if (planets[y].distanceFromEarth < planets[minIndex].distanceFromEarth)
                    {
                        minIndex = y;
                    }
                }
                if (minIndex != x)
                {
                    struct planet temp = planets[x];
                    planets[x] = planets[minIndex];
                    planets[minIndex] = temp;
                }
            }

            for (i = 0; i < n; i++)
            {
                if (planets[i].habitable == 'Y')
                {
                    printf("%s - %.2f light-years\n", planets[i].planetName, planets[i].distanceFromEarth);
                }
            }
            break;

        case 2:
            printf("Enter minimum oxygen level threshold: ");
            // Write the scan statement for the oxygen threshold
            scanf("%f", &oxyThreshold);

            printf("Enter maximum carbon dioxide level threshold: ");
            // Write the scan statement for the carbon dioxide threshold
            scanf("%f", &co2Threshold);

            printf("Planets with oxygen > %.2f%% and carbon dioxide < %.2f%%:\n", oxyThreshold, co2Threshold);
            // Write a loop to check and print planets that meet oxygen and CO2 criteria
            for (i = 0; i < n; i++)
            {
                if (planets[i].atmo.oxygen > oxyThreshold && planets[i].atmo.carbonDioxide < co2Threshold)
                {
                    printf("%s\n", planets[i].planetName);
                }
            }
            break;

        case 3:
            printf("Enter a keyword to search in planet names: ");
            // Write the scan statement for the keyword
            scanf("%s", nameKeyword);

            printf("Planets matching the keyword \"%s\":\n", nameKeyword);
            // Write a loop to search planet names using strstr() and print matching names
            for (i = 0; i < n; i++)
            {
                if (strstr(planets[i].planetName, nameKeyword))
                {
                    printf("%s\n", planets[i].planetName);
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid input\n");
            break;
        }
    }
}
