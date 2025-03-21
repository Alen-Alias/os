#include <stdio.h>

void lfu(int pages[], int n, int capacity) {
    struct Page {
        int pageNo;
        int frequency;
    };
    
    struct Page frame[capacity];
    int page_faults = 0;
    int page_hits = 0;
    float hit_ratio, miss_ratio;
    
    // Initialize frames with -1 to indicate empty
    for(int i = 0; i < capacity; i++) {
        frame[i].pageNo = -1;
        frame[i].frequency = 0;
    }
    
    // Process each page request
    for(int i = 0; i < n; i++) {
        int flag = 0;
        
        // Check if page already exists in frame
        for(int j = 0; j < capacity; j++) {
            if(frame[j].pageNo == pages[i]) {
                flag = 1;
                page_hits++;
                frame[j].frequency++;
                break;
            }
        }
        
        // If page not found, replace using LFU
        if(flag == 0) {
            int min_freq = 999999;
            int replace_idx = 0;
            
            // Find frame with lowest frequency
            for(int j = 0; j < capacity; j++) {
                if(frame[j].pageNo == -1) {
                    replace_idx = j;
                    break;
                }
                if(frame[j].frequency < min_freq) {
                    min_freq = frame[j].frequency;
                    replace_idx = j;
                }
            }
            
            frame[replace_idx].pageNo = pages[i];
            frame[replace_idx].frequency = 1;
            page_faults++;
            
            // Display current frame state
            printf("\nFor page %d: ", pages[i]);
            for(int j = 0; j < capacity; j++) {
                if(frame[j].pageNo == -1)
                    printf("- ");
                else
                    printf("%d(%d) ", frame[j].pageNo, frame[j].frequency);
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
    
    lfu(pages, n, capacity);
    
    return 0;
}