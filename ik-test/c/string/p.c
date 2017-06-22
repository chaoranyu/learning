#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char sss[30][200] = {"MAY MY HEART BE BRAVE, MY MIND FIERCE, AND MY SPIRIT FREE.", 
        "It may look like I'm having really deep thoughts but 99% of the time I'm just thinking about what food I'm going to eat later.",
        "The biggest adventure you can ever take is to live the life of your dreams.",
        "My anxiousness comes from my intelligence.",
        "The more you believe in your own ability to succeed, the more likely it is that you will.",
        "Don't let your happiness be controlled by something you can't control.",
        "We are all in the gutter, but some of us are looking at the star.",
        "No matter how much it hurts now, one day you will look back and realize it changed your life for the better.",
        "If you don't stand for something, you will fall for anything.",
        "Don't ruin a good today by thinking about a bad yesterday. Let it go.",
        "No one can make you feel inferior without your consent.",
        "I sleep so peacefully at night, knowing I am single and nobody cheating me at night.",
        "Do not pray for an easy life, pray for the strength to endure a difficult one.",
        "Sometimes I wish I was a bird...So I could fly over certain people and shit on their heads.",
        "Time you enjoy wasting, was not wasted. ",
        "Remember you will never be completely useless, we can always use you as a bad example.",
        "If travelling was free, you'd never see me again.",
        "That moment when you have so many things to do so you decide to take a nap instead.",
        "When you feel like quitting, think about why you started.",
        "Never make fun of someone who speaks broken English. It means they know another language.",
        "You're only given one little spark of madness. You mustn't lose it.",
        "Take a deep breath. It's just a bad day, not a bad life.",
        "Enjoy your youth. You'll never be younger than you are at this very moment.",
        "Anyone who has never made a mistake has never tried anything new.",
        "For every minute you're angry, you lose 60 seconds of happiness.",
        "I walk slowly, but I never walk backward.",
        "Only those who will risk going too far can possibly find out how far one can go.",
        "Never frown, even when u are sad, because u never know who is falling in love with ur smile.",
        "Having a soft heart in a cruel world is courage not weakness.",
        "Top 4 wishes:\n  1) To earn money without working.\n  2) To be smart without studying.\n  3) To love without being hurt.\n  4) To eat without getting fat."
        };

    srand(time(0));
    printf("%s\n", sss[rand()%30]);
    // printf("%s\n", sss[29]);

    return 0;
}
