#include <stdio.h>

void fifo(int pages[], int n, int capacity) {
    int frame[capacity];
    int page_faults = 0;
    int page_hits = 0;
    float hit_ratio, miss_ratio;
    
    // Initialize frames with -1 to indicate empty
    for(int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    
    // Index to track the oldest page in frame
    int current = 0;
    
    // Process each page request
    for(int i = 0; i < n; i++) {
        int flag = 0;
        
        // Check if page already exists in frame
        for(int j = 0; j < capacity; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                page_hits++;
                break;
            }
        }
        
        // If page not found, replace using FIFO
        if(flag == 0) {
            frame[current] = pages[i];
            current = (current + 1) % capacity;
            page_faults++;
            
            // Display current frame state
            printf("\nFor page %d: ", pages[i]);
            for(int j = 0; j < capacity; j++) {
                if(frame[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frame[j]);
            }
        }
    }
    
    // Calculate ratios
    hit_ratio = (float)page_hits / n;
    miss_ratio = (float)page_faults / n;
    
    printf("\n\nTotal Page Faults: %d", page_faults);
    printf("\nTotal Page Hits: %d", page_hits);
    printf("\nHit Ratio: %.2f", hit_ratio);
    printf("\nMiss Ratio: %.2f\n", miss_ratio);
}

int main() {
    int n, capacity;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the page reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &capacity);
    
    fifo(pages, n, capacity);
    
    return 0;
}