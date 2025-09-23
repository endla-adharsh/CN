#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int sequence_number;
    char data[50]; 
} Frame;

void sortFrames(Frame frames[], int n) {
    Frame temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (frames[j].sequence_number > frames[j + 1].sequence_number) {
              
                temp = frames[j];
                frames[j] = frames[j + 1];
                frames[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_frames;
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    
    Frame *frames = (Frame *)malloc(num_frames * sizeof(Frame));
    if (frames == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < num_frames; i++) {
        printf("Enter sequence number for frame %d: ", i + 1);
        scanf("%d", &frames[i].sequence_number);
        printf("Enter data for frame %d: ", i + 1);
        scanf("%s", frames[i].data); 
    }

    printf("\nFrames before sorting:\n");
    for (int i = 0; i < num_frames; i++) {
        printf("Frame %d: Sequence: %d, Data: %s\n", i + 1, frames[i].sequence_number, frames[i].data);
    }

  
    sortFrames(frames, num_frames);

    printf("\nFrames after sorting:\n");
    for (int i = 0; i < num_frames; i++) {
        printf("Frame %d: Sequence: %d, Data: %s\n", i + 1, frames[i].sequence_number, frames[i].data);
    }
    free(frames);

    return 0;
}
