#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
//draw man
void draw_man(const char *MAN[],int wrongGuess){
    if (wrongGuess==0)printf("%s\n",MAN[0]);
    else if (wrongGuess==1)printf("%s\n",MAN[1]);
    else if (wrongGuess==2)printf("%s\n",MAN[2]);
    else if (wrongGuess==3)printf("%s\n",MAN[3]);
    else if (wrongGuess==4)printf("%s\n",MAN[4]);
    else if (wrongGuess==5)printf("%s\n",MAN[5]);
    else if (wrongGuess==6)printf("%s\n",MAN[6]);
    else printf("%s\n",MAN[7]);
}


void printword(char hiddenWord[],char show[]){
    printf("%s\n",show);
}
//take play input
void plyrInput(char *guess){
    printf("Enter guess:");
    scanf(" %c", guess); 
    
}

//check guess if right or wrong
int checkRorW(char hiddenWord[],char guess,char show[],int *wrongGuess){
    int found = 0;
    
    for (int i = 0; i < strlen(hiddenWord); i++){
        if (hiddenWord[i] == guess) {
            show[i] = guess;
            found = 1;
        }
    }
    
    if (!found) {
        (*wrongGuess)++; 
        printf("Wrong guess! '%c' not in word.\n", guess);
    } else {
        printf("Good guess! '%c' is in the word.\n", guess);
    }
    
    
}
//check if win
bool checkwin(char show[]){
    for(int i = 0; i < strlen(show); i++) {
        if(show[i] == '-') {
            return false;
        }
    }
    return true;
}
//check if lose
bool checklose(int wrongGuess){
    if (wrongGuess>=6)return true;    
    else return false;
}


int main(){
    //declare variables   
             srand(time(NULL));
             const char *MAN[]={"+--+\n|  |\n|\n|\n|\n|\n=====",
                   "+--+\n|  |\n|  O\n|\n|\n|\n=====",
                   "+--+\n|  |\n|  O\n|  |\n|\n|\n=====",
                   "+--+\n|  |\n|  O\n|  |\\\n|\n|\n=====",
                   "+--+\n|  |\n|  O\n|  |\\\n|   \\\n|\n=====",
                   "+--+\n|  |\n|  O\n| /|\\\n|   \\\n|\n=====",
                   "+--+\n|  |\n|  O\n| /|\\\n| / \\\n|\n====="};
             const char *DIC[]= {
                  "abbreviation", "abdomen", "abrupt", "absence", "absolute", "absorption",
                 "abstract", "academy", "acceleration", "accessory", "accident", "account",
                 "achievement", "acidification", "acoustics", "action", "activation", "actress",
                 "adaptation", "addiction", "addition", "address", "adjustment", "administration",
                 "admiration", "adoption", "advanced", "adventure", "advertisement", "afraid",
                 "afternoon", "against", "agenda", "agreement", "airport", "alarm", "algorithm",
                 "allocation", "alpha", "almost", "aluminium", "ambiguity", "ambition", "america",
                 "amphibian", "anaesthesia", "analogy", "analysis", "anchor", "angel", "animation",
                 "anniversary", "announcement", "answer", "apartment", "apparatus", "apparent",
                 "appearance", "appendix", "application", "approval", "approximation", "archaeology",
                 "architecture", "arithmetic", "arrangement", "article", "ascending", "ashamed",
                 "asleep", "assassin", "assembly", "astonishment", "astronomy", "atmosphere",
                 "attraction", "audio", "automatic", "autumn", "awful", "bachelor", "backbone",
                 "background", "bacteria", "balance", "balloon", "banana", "barbecue", "barrier",
                 "baseball", "basketball", "battle", "beaker", "beard", "beast", "beautiful",
                 "beauty", "because", "behaviour", "belief", "benefit", "between", "bidirectional",
                 "biology", "birthday", "blackboard", "blacksmith", "bladder", "blanket", "bleeding",
                 "blender", "blessing", "blood", "bodyguard", "bonus", "bookcase", "bottle",
                 "brain", "branch", "breakfast", "bridge", "brilliant", "bubble", "bucket",
                 "budget", "business", "butcher", "butterfly", "bypass", "cable", "cafeteria",
                 "calculator", "calibration", "campaign", "cancellation", "candidate", "candle",
                 "captain", "carriage", "carpenter", "carrot", "cartoon", "cascade", "casual",
                 "cassette", "castle", "catalyst", "category", "cathode", "cavity", "cement",
                 "ceremony", "certificate", "channel", "chapter", "challenge", "championship",
                 "checkout", "chemistry", "chicken", "children", "chimney", "chocolate", "christmas",
                 "cigarette", "cipher", "circle", "circuit", "circumference", "civilization",
                 "classification", "classroom", "client", "clearance", "clothes", "coconut",
                 "coincidence", "collection", "colleague", "comfortable", "command", "comment",
                 "communication", "company", "compact", "comparison", "competition", "compression",
                 "computer", "concentration", "confidence", "conflict", "confusion", "consciousness",
                 "consequence", "conservation", "conspiracy", "conversation", "control", "cookies",
                 "country", "cousin", "cowboy", "crystal", "current", "daughter", "database",
                 "delete", "demonstration", "department", "derivative", "description", "design",
                 "desire", "despair", "desert", "desktop", "destination", "destruction", "detail",
                 "device", "devil", "dictionary", "difference", "difficulty", "diffusion", "digital",
                 "dimension", "dining", "dinner", "direction", "directory", "disappointment",
                 "disaster", "disease", "diving", "divorce", "document", "doctorate", "dollar",
                 "donkey", "doorbell", "doubt", "dream", "dynamic", "eagle", "earthquake",
                 "economics", "education", "egyptiwan", "elasticity", "electron", "electronic",
                 "elevator", "emission", "emotion", "encouragement", "encryption", "enemy",
                 "engagement", "engineering", "english", "environment", "equalizer", "eraser",
                 "error", "eternity", "exactly", "example", "excellence", "excitement", "excuse",
                 "expectation", "expensive", "experience", "experiment", "explanation", "expression",
                 "extension", "external", "extreme", "failure", "family", "fashion", "football",
                 "future", "freedom", "frequency", "friend", "function", "funeral", "furniture",
                 "garden", "garment", "genius", "global", "glory", "glasses", "grandfather",
                 "grave", "greenhouse", "grocery", "guitar", "happen", "happiness", "harbour",
                 "hardware", "harmony", "harvest", "hatred", "health", "heaven", "hesitation",
                 "history", "honour", "housekeeper", "hundred", "hunger", "human", "humanity",
                 "illusion", "illustration", "imagination", "impossible", "impression", "induction",
                 "infinity", "injection", "institution", "instrument", "insurance", "intelligence",
                 "interference", "internet", "intersection", "intuition", "invitation", "island",
                 "isolation", "isometric", "iteration", "jockey", "journal", "kangaroo", "kidnap",
                 "keyboard", "kingdom", "knowledge", "ladder", "landmark", "language", "laser",
                 "laughter", "layer", "legend", "license", "lightning", "limitation", "logic",
                 "machine", "magician", "magnet", "magnification", "management", "mathematics",
                 "matrix", "matter", "measurement", "mechanism", "meeting", "member", "memory",
                 "merchant", "message", "method", "microphone", "microwave", "miracle", "mixture",
                 "moment", "monkey", "morning", "mountain", "musician", "mystery", "nationality",
                 "necessary", "network", "nightmare", "nucleus", "number", "ocean", "office",
                 "operation", "opportunity", "opposite", "overflow", "overcome", "ozone", "parameter",
                 "passion", "password", "pattern", "peace", "permission", "personality", "philosophy",
                 "picture", "planet", "pleasure", "policeman", "politics", "positive", "possession",
                 "poverty", "power", "pressure", "process", "production", "profession", "project",
                 "promise", "prophet", "protection", "psychology", "puzzle", "pyramid", "queen",
                 "question", "reaction", "reality", "receiver", "recipe", "recognition", "record",
                 "reflection", "relativity", "resistance", "resort", "restaurant", "reward",
                 "robot", "saturn", "satisfaction", "science", "scissors", "screen", "secondary",
                 "secret", "security", "selection", "sensitivity", "servant", "service", "signal",
                 "silence", "silver", "simulation", "situation", "smash", "source", "sphere",
                 "spider", "spirit", "spring", "statement", "statistics", "stranger", "strength",
                 "stress", "string", "submarine", "substitution", "subtraction", "success",
                 "suggestion", "sunlight", "superman", "supermarket", "superstition", "supply",
                 "surprise", "symptom", "system", "teacher", "technology", "television", "temple",
                 "threshold", "thousand", "titanic", "tolerance", "tomorrow", "tongue", "tower",
                 "traffic", "transformation", "transistor", "transmitter", "treasure", "treatment",
                 "trousers", "tutorial", "tyrant", "undertaker", "university", "valley", "vibration",
                 "video", "virtue", "vision", "volcano", "voltage", "warning", "wealth", "weapon",
                 "whispering", "widow", "wind", "window", "winter", "wisdom", "wishing", "woman",
                 "wonderful", "worry", "wrong", "xerox", "yourself", "zebra"};
             char* colors[] = {"\033[1;31m", "\033[1;33m", "\033[1;32m", 
                          "\033[1;36m", "\033[1;34m", "\033[1;35m"};
             char hiddenWord[45]; 
             char show[100];
             char guess;  
             int randomnum=rand()%sizeof(DIC)/sizeof(DIC[0]) ;
             strcpy(hiddenWord,DIC[randomnum]);          
             int wrongGuess=0;
             bool isrunning=true;                 
             printf("%s  _    _                                         \n", colors[0]);
             printf("%s | |  | |                                            \n", colors[0]);
             printf("%s | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  \n", colors[1]);
             printf("%s |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n", colors[2]);
             printf("%s | |  | | (_| | | | | (_| | | | | | | (_| | | | |\n", colors[3]);
             printf("%s |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n", colors[4]);
             printf("%s                     __/ |                      \n", colors[5]);
             printf("%s                    |___/                       \n", colors[5]);
             printf("\033[0m");
             for(int i =0;i<strlen(hiddenWord);i++){
                show[i]='-';
             }
             show[strlen(hiddenWord)] = '\0';
             while (isrunning){
                
                draw_man(MAN,wrongGuess);
                printword(hiddenWord,show);
                plyrInput(&guess);
                checkRorW(hiddenWord,guess,show,&wrongGuess);
                if (checkwin(show)){
                        printf("\033[1;32m"); 
                        printf(" __     __          __          ___       _ \n");
                        printf(" \\ \\   / /          \\ \\        / (_)     | |\n");
                        printf("  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __ | |\n");
                        printf("   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\| |\n");
                        printf("    | | (_) | |_| |    \\  /\\  /  | | | | |_|\n");
                        printf("    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_(_)\n");
                        printf("\033[0m");  
                        sleep(10);
                        isrunning=false;
                }
                else if (checklose(wrongGuess)){
                    printf("\033[1;31m"); 
                    printf("   _____                         ____                 \n");
                    printf("  / ____|                       / __ \\                \n");
                    printf(" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
                    printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n");
                    printf(" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
                    printf("  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n");
                    printf("\033[0m"); 
                    sleep(10);
                    isrunning=false;
                }
                else isrunning=true;
             }
             
    return 0;
}

