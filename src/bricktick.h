/* Bricktick brick breaker
 * This software is public domain.
 * See the file UNLICENSE.TXT for more information.
 * Created in 2014 by Subsentient
 */

#define true 1
#define false 0

#define DEFAULT_PADDLE_LENGTH (COLS / 10) /*How long the paddle is.*/
#define DEFAULT_PADDLE_MOVE (DEFAULT_PADDLE_LENGTH / 2)
#define BRICKS_PER_LINE 20 /*Ten bricks per line of text*/
#define BRICK_LINE_COUNT 7  /*Four lines of bricks.*/
#define BALL_X_SPEEDMULTIPLIER (COLS / 80)
#define BALL_Y_SPEEDMULTIPLIER (LINES / 24)

typedef signed char Bool;

typedef enum { LEFT, RIGHT, X_NEUTRAL } DirectionX;
typedef enum { DOWN, UP, Y_NEUTRAL } DirectionY;

struct BALL
{
	int X, Y;
	DirectionX DirX;
	DirectionY DirY;
};

struct PADDLE
{
	int X;
	int Length;
};

struct BRICK
{
	int X1, X2, Y;
	unsigned int Visible : 1;
	unsigned int CF : 1; /*Zero, we are green, one, we are blue.*/
};

struct BRICKSTRIKE
{
	enum StrikeV { STRIKE_VNONE, STRIKE_BOTTOM, STRIKE_TOP } StrikeV;
	enum StrikeH { STRIKE_HNONE, STRIKE_LEFT, STRIKE_RIGHT } StrikeH;
	struct BRICK *Brick;
};

/*Functions.*/
extern void ResetBall(struct BALL *Ball);
extern void DrawBall(struct BALL *Ball);
extern void DeleteBall(struct BALL *Ball);
extern void MoveBall(struct BALL *Ball);
extern void BounceBallY(struct BALL *const Ball, DirectionY Direction);
extern void BounceBallX(struct BALL *const Ball, DirectionX Direction);

extern void DrawPaddle(struct PADDLE *Paddle);
extern void ResetPaddle(struct PADDLE *Paddle);
extern void DeletePaddle(struct PADDLE *Paddle);
extern void MovePaddle(struct PADDLE *Paddle, DirectionX Direction);
extern Bool CheckBallHitPaddle(struct BALL *Ball, struct PADDLE *Paddle);

extern void DrawMessage(const char *const Message);
extern void DeleteMessage(void);
extern void DrawLives(int Lives);
extern void DrawScore(unsigned long Score);
extern void WaitForUserLaunch(void);

extern void DrawBrick(struct BRICK *Brick);
extern Bool BallStruckBrick(const struct BALL *const Ball, struct BRICKSTRIKE *const Strike);
extern void InitBricks(void);
extern void DrawAllBricks(void);
extern void DeleteAllBricks(void);
extern void DeleteBrick(struct BRICK *Brick);

/*Globals*/
extern int Lives;
extern unsigned long Score;
extern Bool UseColor;
extern struct BRICK Bricks[BRICK_LINE_COUNT][BRICKS_PER_LINE];
