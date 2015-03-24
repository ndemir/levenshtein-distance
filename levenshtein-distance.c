#include <stdio.h>
#include <stdlib.h>
#include <supergetopt.h>
#include <math.h>
#include <string.h>
#include "levenshtein.h"

int main(int argc, char *argv[]){

	int argPos;

	char *str1 = NULL;
	char *str2File = NULL;
	char *outputFile = "-";
	int maxDistance = -1;
	float distanceRatio = 25;
	int includeStr1 = 0;

	int extraArgCount = superGetOpt(argc,argv, &argPos,
			"--string1 %s", &str1, "compare this string",
			"--string2-file %s", &str2File, "compare the string1 with the strings in string2-str2File",
			"--max-distance %d", &maxDistance, "show strings which has  under this value",
			"--max-distance-ratio %f",&distanceRatio, "calculate max-maxDistance by using this value, default: 25",
			"--output-file %s", &outputFile, "write output to this file, default: stdout",
			"--include-string1", &includeStr1, "include string 1 in output",
			(char * ) 0 );

	if (maxDistance == -1)
		maxDistance = round(strlen(str1)*distanceRatio/100.0);

	FILE *outputFp;
	if (strcmp(outputFile, "-") == 0){
		outputFp = stdout;
	}else{
		outputFp = fopen(outputFile, "w");
	}

	FILE *str2Fp;//str2-file pointer
	char *str2 = NULL;
	size_t len = 0;
	ssize_t read;

	str2Fp = fopen(str2File, "r");
	if (str2Fp == NULL){
		printf("can not open str2File");
		exit(EXIT_FAILURE);
	}


	int calculatedDistance;
	while ((read = getline(&str2, &len, str2Fp)) != -1) {

		int l = strlen(str2);
		if (l > 0 && str2[l-1] == '\n')
		  str2[l-1] = 0;

		calculatedDistance = levenshtein(str1, str2);
		if (calculatedDistance <= maxDistance){
			if (includeStr1 == 1) {
				fprintf(outputFp,"%s;%s;%d\n", str1, str2, calculatedDistance);
			}else{
				fprintf(outputFp,"%s;%d\n", str2, calculatedDistance);
			}
		}
	}

	fclose(str2Fp);
	if (str2)
	   free(str2);
	exit(EXIT_SUCCESS);

}
