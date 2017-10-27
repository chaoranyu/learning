#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_BLACK     "\033[30m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_RED       "\033[31m"
#define COLOR_PURPLE    "\033[35m"
#define COLOR_BLUE      "\033[34m"
#define COLOR_SKYBLUE   "\033[36m"
#define COLOR_YELLOW    "\033[33m"

#define COLOR_DEFAULT   "\033[m"

int main()
{
    char quotes[30][200] = {
        "MAY MY HEART BE BRAVE, MY MIND FIERCE, AND MY SPIRIT FREE.", 
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

    char lines[2][2048] =
    {
        "Frodo: I can't do this, Sam.\n"
        "Sam:   I know. It's all wrong. By rights, we shouldn't even be here. But we are.\n"
        "Sam:   It's like in the great stories, Mr. Frodo.\n"
        "       The ones that really mattered. Full of darkness and danger they were.\n"
        "       And sometimes you didn't want to know the end, because how could the end be happy?\n"
        "       How could the world go back to the way it was, when so much bad had happened?\n"
        "Sam:   But in the end, it's only a passing thing, this shadow.\n"
        "       Even darkness must pass. A new day will come.\n"
        "       And when the sun shines it will shine out the clearer.\n"
        "       Those were the stories that stayed with you, that meant something.\n"
        "       Even if you were too small to understand why.\n"
        "       But I think, Mr. Frodo, I do understand. I know now.\n"
        "Sam:   Folk in those stories, had lots of chances of turning back, only they didn't.\n"
        "       They kept going, because they were holding on to something.\n"
        "Frodo: What are we holding on to, Sam?\n"
        "Sam:   That there's some good in this world, Mr. Frodo. And it's worth fighting for.",
        "hello, world."
    };

    char quotes_cn[12][256] =
    {
        "生命本来就是一个笑话，死亡则是最后一次插科打诨。\n——约翰·埃尔文",
        "在恋爱中，大多数人寻找永恒的家园，而另有一些人，他们属于少数，则寻求永恒的航行。\n——瓦尔特·本雅明",
        "真正有气质的淑女，从不炫耀她所拥有的一切，她不告诉人她读过什么书，去过什么地方，有多少件衣服，买过什么珠宝，因为她没有自卑感。\n——亦舒《圆舞》",
        "另她反感的，远不是世界的丑陋，而是这个世界所戴的漂亮面具。\n——米兰•昆德拉《生命不能承受之轻》",
        "人们习惯于将我当做一面镜子，而不是一个人。他们看见的不是我，而是他们各自的想法。\n——玛丽莲•梦露《我的故事》",
        "优雅是一件很难的事情，比矜持难，比无赖也难。\n矜持能装，无赖容易，可优雅不行。\n优雅要气质，要资历，要岁月沉淀，要那份从容和云淡风轻。\n——雪小禅",
        "当人以自己的身份说话的时候，便越不是自己。给他一个面具，他就会告诉你事实真相。\n——王尔德",
        "人的本能是追求从他身边飞走的东西，却逃避追逐他的东西。\n——伏尔泰",
        "高尚不是单纯的美好，也是对一切事物理解之后的超然，对善与恶的一视同仁，用悲悯的目光，看待世界。\n——余华",
        "对于一座城市，你所喜欢的不在于她的7个或者70个奇景，而在于她对你心中问题所给予的答复。\n——伊塔洛·卡尔维诺",
        "上帝用六天的时间创造了世界，而第七天，是酒醒后的痛苦。\n——罗伯特·卡帕",
        "我们老是被教育着要过正确的生活，不能犯错。\n可是我却觉得，当错误显得越严重，我就越有机会摆脱束缚，过真正的生活。\n——恰克·帕拉尼克《隐形怪物》" 
    };

    srand(time(0));
    printf("%s%s%s\n", COLOR_BLUE, quotes[rand()%30], COLOR_DEFAULT);
    //printf("%s%s%s\n", COLOR_GREEN, quotes_cn[rand()%12], COLOR_DEFAULT);

    return 0;
}
