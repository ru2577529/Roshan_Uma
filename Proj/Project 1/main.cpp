/* 
 * File:   main.cpp
 * Author: Roshan Uma
 * Created on January 26, 2018  5:11 PM
 * Purpose:  Simulate an amazingly awesome maze game that will test the true skill of a person through intense challenge and rigor.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char** argv) {
  
unsigned seed = time(0);
srand(seed);  
  
// Introduction to the Game; Input Name and Trait, HP; LINES 16-32;
string charName, charTrait;
float userHP = 100;
char ch;

cout << "You wake up dazed and confused. You barely remember anything that is going on and you do not know where you are at. You try to remember your name." << endl;
cout << "Please enter your character's name:   ";
cin >> charName;
cin.ignore();
cout << endl;
cout << "What is your best talent in one word:    ";
cin >> charTrait;
cin.ignore();
cout << endl;
cout << "Ahhh, you are " << charName << " the one best at " << charTrait << ". Your journey starts here.\n";
cout << "You look up and see you are standing by a large gate with the word 'Labrynth' etched into the wooden sign. You turn back around to see if you can escape, but the only black nothingness greets you in the other direction. A feeling of great fear falls over your shoulders and shivers down your spine. You realize that your Journey Begins here.... (Press Enter to Continue)";
cin.get();
cout << endl;

// Approach first split... Right, Left. LINES 35 - 54
char desOne;

cout << "As you begin your journey, you choose to travel down a straight path. You walk to a fork in the road. Do you go right or left (enter r for right, enter l for left):  ";
cin >> desOne;
cout << endl;
cin.ignore();
    if (desOne == 'r') {
      cout << "The pathway seems clear and uncomfortably safe. You proceed through the labrynth. Press enter to continue.";
      cin.get(ch); 
      cout << endl;
    }
    else if (desOne == 'l') {
      cout << "You walk down a path adorned with fruits and berries. The smell is much more nice here and you feel relaxed. Suddenly your stomach growls. You are hungry. You decide to try a seemingly harmless berry to satisify your hungry. After a few minutes of walking you feel faint. You stop to take a breather but realize the berry you ate was poisonous! You lay down and after a few minutes, you perish.\n";
      cout << "YOU HAVE DIED! Replay game to try again!!";
      return 0;
    }
    else {
      cout << "Please enter r or l:  ";
      cin >> desOne;
      cin.ignore();    }
      
// 3 Doors Game - Blue Door = Brick Wall, smashes. Pink Door = Good, LINES 57 - 80
char desTwo;

cout << "Walking down the right pathway, the trees start getting closer to you. You feel as if the pathway is narrowing, yet you continue. The trees eventually narrow in so much you can barely squeeze your way through. You make it, barely, and find yourself inside what seems to be a large room made completely of wood. You see 3 Doors across the room.\n";
cout << "You see a blue, pink, and green door. Which do you choose? (b for blue, p for pink, g for green):  ";
cin >> desTwo;
cin.ignore();
cout << endl;
switch(desTwo) {
  case 'b': {
    cout << "You open the blue door. To your surprise, a brick wall confronts you. You deem it is no threat and proceed to open another door when the wall collapes in. A flying brick bonks your head! (-10 HP) The pathway is open. (press enter to continue).\n";
    userHP -= 10;
    cout << "Current HP: " << userHP << endl;
    cin.get(ch); break;
  }
  case 'p': {
    cout << "You open the pink door. There is nothing but an open pathway ahead of you. You continue onward. \n";
    cin.get(ch); break;
  }
  case 'g': {
    cout << "You open the green door. For some odd reason, a black hole is what was on the other side of the door. You are sucked in and crush by an infinite amount of gravity. You perish.\n";
    cout << "YOU HAVE DIED! Replay the game to try again!!\n";
    
    return 0;
  }
  
}
// Passes Doors Game, Walks down alleyway. Approaches ominous trader. LINES 84 - 97
char desThree;
cout << "As you continue finding your way through the twisted labrynth, someone confronts you. You are wary when approaching. The person reveals himself to be a trader. (Press Enter to Continue)\n";
cin.get(ch);
cout << "'I offer you a hint for your future endevours,' states the trader, 'but it comes at a price of 10 HP. Do you accept the trade? (y for yes, n for no):   ";
  cin >> desThree;
  cout << endl;
  cin.ignore();
    if (desThree == 'y') {
    userHP -= 10;
    cout << "'Roses are always a right choice for a lovely woman,' the old man mumbles. You feel a tad winded taking the hit, but you regain composure shortly after and move onwards. (Press enter to continue)\n";
    cout << "Current HP = " << userHP << endl;
    cout << endl;
    }
    if (desThree == 'n') {
    cout << "You thank the trader for the offer but move on.\n";
}

// Continues down pathway Right/Left;
char desFour;
char descFourOne;
cout << "You find that a wall is stopping your advance. You can only go right or left. Which way do you choose to go (enter r for right, enter l for left):  ";
cin >> desFour;
cout << endl;
cin.ignore();
if (desFour == 'r') {
  cout << "Your pathway proves to lead through a large forest of roses! You turn around to choose the other direction but you feel an intense heat! Do you turn around and face the fire (-10 HP) or force your way through the thorns (-3 HP for the next 3 decicions, excluding battle) Enter t for thorns or f for fire: \n";
  cin >> descFourOne;
  cin.ignore();
  cout << endl;
  if (descFourOne == 'f') {
    cout << "You brave the heat of the flames. To your surprise, you only take a few minor burns and make it to the correct path. (-10 HP) (Press Enter to continue):  ";
    userHP -= 10;
    cout << "Current HP: " << userHP << endl;
    cin.get(ch);
    cout << "Current HP: " << userHP << endl; 
    cout << endl;
  }
  if (descFourOne == 't') { 
    cout << "You decide to take your chance with the thorns. After (barely) making it through, you noticed you are completely covered with thorns! (-3 HP over next 3 Decisions, excluding battle.) (Press enter to continue)";
    cin.get(ch);
    cout << endl;
  }
}
else { cout << "You decide to take the left pathway. Much to your surprise, there is nothing awaiting you but an open pathway. You continue. (Press enter to continue) \n";
  cin.get(ch); }
  
// Approaches a wild sheepdog. Attack = 5, Defend = Reduces by 2, Enemy random 1-5;
cout << "You hear low growl up the pathway. A wild sheepdog leaps from the bushes and attacks you! You enter battle. (Press Enter to Coninue)" << endl;
int dogHP = 1;
int dogAtk;
const int dogAtk_min = 1;
const int dogAtk_max = 5;
int userAtk = 5;
int userDef = 3;
char userAction;

if (descFourOne == 't') {
  cout << "The thorns hurt you! Take 3 damage. (Press enter to continue)" << endl;
  userHP -= 3;
  cout << "Current HP: " << userHP << endl;
}

cout << "Sheepdog HP: 15 (heals 1 per turn) " << charName << "'s Attack: 5 Heal: 3" << endl;
cout << endl;

for(int i = 15; i > dogHP; i++) {
  dogAtk = (rand() % (dogAtk_max - dogAtk_min +1) + dogAtk_min);
  cout << "What do you do? (Enter a for attack, enter h for heal if below 100 HP):  " << endl;
  cin >> userAction;
  cin.ignore();
  if (userAction == 'a') {
    i -= 5;
    cout << "You attack!" << endl;
  }

  if (userAction == 'h') {
    userHP = userHP < 100 ? userHP + 3 : userHP + 0;
    cout << "You heal!" << endl;
  }  
  cout << "Sheepdog HP: " << i << endl;
  userHP -= dogAtk;
  cout << "The Sheepdog Attacks! Current HP:  " << userHP << endl;
  cout << "The Sheepdog heals for 1..." << endl;  
    if (userHP <= 0) {
      cout << "YOU HAVE DIED! Replay to try again!" << endl;
      return 0;
    }
  }

cout << "You have successfully defeated the wild Sheepdog. (Press Enter to continue)" << endl;
cin.get(ch);

// Right left, Right = Dead end, go back. Left = continue forward.
char desFive;
if (descFourOne == 't') {
  cout << "The thorns hurt you! Take 3 damage. (Press enter to continue)" << endl;
  userHP -= 3;
  cout << "Current HP: " << userHP << endl;
}
cout << "You are tired after the struggle against the Sheepdog. You walk slowly towards another fork. Right (r) or Left (l): ";
cin >> desFive;
cin.ignore();
cout << endl;

if (desFive == 'r') {
  cout << "You've hit a dead end. However, you find a tranquil area where you decide to rest. (Heal 10 HP) You go back and take the left pathway." << endl;
  userHP += 10;
  cout << "Current HP: " << userHP << endl;
}
if (desFive == 'l') {
  cout << "The pathway continues forward. You find a nice place to sit down and rest for a few minutes before continuing onward. (Heal 5 HP)" << endl;
  userHP += 5;
  cout << "Current HP: " << userHP;
}

// Straight, Left, Straight = Continues, Left = Continues
char desSix;
if (descFourOne == 't') {
  cout << "The thorns hurt you! Take 3 damage. (Press enter to continue)" << endl;
  userHP -= 3;
  cout << "Current HP: " << userHP << endl;
}
cout << "You are now at a straight or left choice. Which way do you go? (Enter s for straight, enter l for left):  ";
cin >> desSix;
cin.ignore();
cout << endl;
if (desSix == 's') {
  cout << "You are running down an empty pathway. Everything seems to be all clear when WAM! You run into a wall at lightning fast speed (Take 5 Damage). You try to regain your balance and head the opposite direction." << endl;
  userHP -=5;
  cout << "Current HP: " << userHP;
  cout << endl << endl;
}
if (desSix == 'l') {
  cout << "You walk down an open pathway. This appears to be the correct choice." << endl;
  cout << endl;
}

// A band of sirens attempt to attack you!
cout << "The area you are walking in becomes increasily misty. You notice the floor is covered in water and you have to trudge to make it through. You have entered a more swampy area. You hear faint singing in the distance. Over the horizon you notice 2 strange creatures, later to be discovered as sirens. Their singing causes you to draw closer against your will. You struggle and attempt to break free from their spell to continue through the labrynth." << endl;
cout << endl;
cout << "The sirens music draw you in. They attack! You are knocked to the ground. While recovering your stance, you discover something shining in the water. You've obtained a dagger! (8 Damage) You must enter battle in orded to pass through." << endl;
cout << endl;
int sirenHP = 1;
int sirenAtk;
int sirenAtk_Min = 1;
int sirenAtk_Max = 7;
int userDagger = 8;

cout << "Siren HP: 30\n";
cout << charName << "'s Attack: 8 Heal: 3" << endl;
cout << "Enter a for attack, h for heal: " << endl;

  for (int s = 30; s >= sirenHP; s+=2) {
    sirenAtk = (rand() % (sirenAtk_Max - sirenAtk_Min +1) + sirenAtk_Min);
    cout << "What do you do? (Enter a for attack, enter h for heal if below 100 HP  " << endl;
    cin >> userAction;
    cin.ignore();
    cout << endl;
      if (userAction == 'a') {
      s -= userDagger;
      cout << "You attack!" << endl;  }
      if (userAction == 'h' && userHP <= 100) {
      userHP += 3;
      cout << "You heal!" << endl;  }  
      
  cout << "Siren HP: " << s << endl;
  userHP -= sirenAtk;
  cout << "The Siren Attacks! Current HP:  " << userHP << endl;
  cout << "The Siren heals for 2..." << endl;  
    if (userHP <= 0) {
      cout << "YOU HAVE DIED! Replay to try again!" << endl;
      return 0;
    }  
}
cout << "You have successfully defeated the Singing Siren. (Press Enter to continue)" << endl;
cin.get(ch);

// After the sirens, left/right/straight. Left/Right = Continue to another left/right, both fail, go back to straight.
char desSeven;
char desEight;
cout << "You feel winded, but quite accomplished, after making it through the previous fight. You sense a calmness in the air as you continue your journey. (Press enter to continue)" << endl;
cin.get(ch);
cout << "You are confront with 3 roads, one going to the left(l), to the right(r), and straight(s). Which do you choose?  ";
cin >> desSeven;
cin.ignore();
cout << endl;
if (desSeven == 'l') {
  cout << "You continue forward. Another Right(r) and Left(l) crossroad appears. Which way do you go?  ";
  cin >> desEight;
  cin.ignore();
  cout << endl;
  if (desEight == 'r') {
    cout << "You find yourself at a dead end. You turn around and go back." << endl;
  }
  if (desEight == 'l') {
    cout << "You find yourself at a dead end. You stop to rest for a few minutes before heading back. (Heal 5 HP)" << endl;
    userHP += 5;
    cout << "Current HP: " << userHP;
  }
}
if (desSeven == 'r') {
  cout << "You continue forward. Another Right(r) and Left(l) crossroad appears. Which way do you go?  ";
  cin >> desEight;
  cin.ignore();
  cout << endl;
  if (desEight == 'r') {
  cout << "You find yourself at a dead end and are quickling chased back to the previous turn by a Sheepdog!" << endl;
  }
  if (desEight == 'l') {
    cout << "You find yourself at a dead end. You stop to rest for a few minutes before heading back. (Heal 10 HP)" << endl;
    userHP += 10;
    cout << "Current HP: " << userHP << endl;
    cout << endl;
  }
}

// You find a nice inn to stay at, you speak with the attendant. He asks if you have seen a shady trader around, you state yes. If you have done business with him, leave inn, if no, stay at inn. Recover 20 HP. Save State 3
cout << "You notice a small inn on the side of the road with the lights on. You decide to go inside. There, you begin speaking with the Inn Keeper... (enter)" << endl;
cin.get(ch);
cout << "'Welcome to my Inn!' exclaims the Inn Kepper. 'It is quite cold and dangerous outside. I've heard of a lonely merchant walking throuhg these parts of the forest. Have you seen him?' asks the Inn Keeper. You nod your head. 'My gosh I hope you did not deal with the devil himself! Far too many tainted souls walk these woods! Tell me honestly, did you deal with the trader?' (enter)" << endl;
cin.get(ch);

bool goodAnswer;
goodAnswer = desThree == 'n';
bool badAnswer;
badAnswer = desThree == 'y';
if (badAnswer == 1) {
  cout << "You regretfully tell the Inn Keeper you have. The Inn Keeper's smile fades. 'Leave this place at once!' he barks. You leave the inn and continue the journey, cold." << endl;  }
if (goodAnswer == 1) {
  cout << "'Oh thank goodness! I am glad to see some people are able to resist temptation. I am very happy to provide you with a room for the night.' (Heal 20 HP)" << endl;
  userHP += 20;
  cout << "Current HP: " << userHP << endl;  }  

// Path leading up to final boss
cout << "You can see the end of the labrynth approaching you. The thought of escape fills you with excitement! Before you begin sprinting to the end, you notice a glowing chest tucked away inside a bush. You grab and open it..." << endl;

  cout << "You find a healing potion! (Heals 15 HP)" << endl;
  userHP += 15;
  cout << "Current HP: " << userHP;
  cin.get(ch); 

cout << "Amongst this, you also find a healing tome! (Exponential Healing!)" << endl;
cin.get(ch);
  
// FINAL BOSS FIGHT!  
  
cout << "After opening the chest, you begin sprinting towards the gate only to be startle by huge footsteps. Something comes bursting out of the ground! You stand face to face with a large orc prepared to stop you at all costs! You must fight to escape!" << endl; 

int bossHP = 0;
int bossAtk;
int bossAtk_MIN = 1;
int bossAtk_MAX = 10;
int tomeHeal_MIN = 1;
int tomeHeal_MAX =3;
int x;

cout << "Orc HP: 100" << endl;
cout << charName << " 's Attack: " << userDagger << endl;
cout << charName << " 's Heal: 6" << endl;
  
for (int c = 100; c > bossHP; c+=3) { 
  while (c >= 60) {
  bossAtk = (rand() % (bossAtk_MAX - bossAtk_MIN +1) + bossAtk_MIN);  
    cout << "What do you do? (Enter a for attack, enter h for heal if below 100 HP  " << endl;
    cin >> userAction;
    cin.ignore();
    cout << endl;
      if (userAction == 'a') { // ATTACK
      c -= userDagger;
      cout << "You attack!" << endl;  }
      if (userAction == 'h' && userHP <= 100) { // HEAL
      x = (rand() % (tomeHeal_MAX - tomeHeal_MIN +1) + tomeHeal_MIN);  
      userHP += pow(x,6);
      cout << "You heal!" << endl;  }
      
      cout << "Orc HP: " << c << endl;
      userHP -= bossAtk;
      cout << "The Orc Attacks! Current HP:  " << userHP << endl;
      cout << "The Orc heals for 3..." << endl;  
      if (userHP <= 0) {
      cout << "YOU HAVE DIED! Replay to try again!" << endl;
      return 0;
    }  
  }
  do {
    bossAtk = (rand() % (bossAtk_MAX - bossAtk_MIN +1) + bossAtk_MIN);  
    cout << "What do you do? (Enter a for attack, enter h for heal if below 100 HP  " << endl;
    cin >> userAction;
    cin.ignore();
    cout << endl;
      if (userAction == 'a') { // ATTACK
      c -= userDagger;
      cout << "You attack!" << endl;  }
      if (userAction == 'h' && userHP <= 100) { // HEAL
      x = (rand() % (tomeHeal_MAX - tomeHeal_MIN +1) + tomeHeal_MIN);  
      userHP += pow(x,6);
      cout << "You heal!" << endl;  }
      
      cout << "Orc HP: " << c << endl;
      userHP -= (bossAtk * 2);
      cout << "The Orc Attacks even HARDER!!! Current HP:  " << userHP << endl;
      cout << "The Orc heals for 3..." << endl;  
      if (userHP <= 0) {
      cout << "YOU HAVE DIED! Replay to try again!" << endl;
      return 0;
    } 
     }
while (c < 60 && c > 0); }

cout << "You finally defeat the orc and escape the labrynth! Congratulations!!";
  
  return 0;
}
