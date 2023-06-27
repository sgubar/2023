#include <stdio.h>
#include <stdlib.h>
#include "arraytriangle.h"
#include "triangle.h"
#include <string.h>


ArrayOfTriangles *createArrayOfTriangles(int aReserved) {
    ArrayOfTriangles *result = (ArrayOfTriangles *)malloc(sizeof(ArrayOfTriangles));
	if (NULL != result) {
		result->preservedCount = (aReserved > 0) ? aReserved : 2;
		result->count = 0;
		result->storage = (Triangle **)malloc(sizeof(Triangle *) * result->preservedCount);

		if (NULL == result->storage) { // if failed to alloc memory for internal storage
			free(result);
			return NULL;
		} else {
			bzero(result->storage, sizeof(Point *) * result->preservedCount);
		}
	}
	return result;
}

void destroyArrayOfTriangles(ArrayOfTriangles *anArray) {
    if (NULL == anArray) {
		return ;
	}

	free(anArray->storage);
	free(anArray);
}

int addTriangle(ArrayOfTriangles *anArray, Triangle *aTriangle) {
    if (NULL == anArray) {
		return -1;
	}

	if (anArray->count == anArray->preservedCount) {
		if (0 != extendArrayOfTriangles(anArray)) {
			return -1;
		}
	}

	anArray->storage[anArray->count] = aTriangle;
	anArray->count++;
    return anArray->count-1;
}

int addTriangleByCords(ArrayOfTriangles *anArray, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (NULL == anArray) {
		return -1;
	}

	if (anArray->count == anArray->preservedCount) {
		if (0 != extendArrayOfTriangles(anArray)) {
			return -1;
		}
	}

    Triangle*A = createTriangle(x1, y1, x2, y2, x3, y3);
    if (NULL == A) {
		return -1;
	}

	anArray->storage[anArray->count] = A;
	anArray->count++;
    return anArray->count-1;
}

int addTriangleAtIndex(ArrayOfTriangles *anArray, Triangle *aTriangle, int index) {
    if (NULL == anArray) {
		return -1;
	}
    if(index < 0) {
        return -1;
    }

    if (index < anArray->count) {
        Triangle *toDelete = anArray->storage[index];
        anArray->storage[index] = aTriangle;
        destroyTriangle(toDelete);
        return 0;
    }
    addTriangle(anArray, aTriangle);
    return 0;
}

Triangle *getTriangleAt(ArrayOfTriangles *anArray, int aIndex) {
    if (NULL == anArray || aIndex >= anArray->count) {
		return NULL;
	}

	return anArray->storage[aIndex];
}

void printArrayOfTriangles(ArrayOfTriangles *anArray) {
    if (NULL == anArray) {
		return;
	}
    printf("[");
	for (int i = 0; i < anArray->count; i++) {
		printTriangle(anArray->storage[i]);
        printf("; ");
	}
    printf("]\n");
}

int countArrayOfTriangles(ArrayOfTriangles *anArray) {
    return (NULL != anArray) ? anArray->count : -1;
}

int extendArrayOfTriangles(ArrayOfTriangles *anArray) {
	if (NULL == anArray) {
		return 1; //Bad input parameters
	}

	anArray->preservedCount *= 2;
	Triangle **local = (Triangle **)malloc(sizeof(Triangle *) * anArray->preservedCount);

	if (NULL == local) {
		return 2; //Couldn't create local
	}

	memcpy(local, anArray->storage, anArray->count * sizeof(Triangle *));
	free(anArray->storage);
	anArray->storage = local;
	return 0;
}
