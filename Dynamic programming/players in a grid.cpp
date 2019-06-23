/*There is a 2D grid and there are two players P1 and P2. Their x,y positions are given. Then there are N gems on the grid and their positions are also given. 
The two players together are supposed to collect the gems in the given sequence making minimum moves (movement in all 8 directions is considered as 1 move). 
Note: the gems should be collected in the given order by either one of the players and then their position then becomes the position of the gem.*/

public int determineMinimumMoves(Point positionPlayer1, Point positionPlayer2,
            final Point... gems) {

        if (positionPlayer1 == null) {
            throw new IllegalArgumentException("Player 1 is null");
        } else if (positionPlayer2 == null) {
            throw new IllegalArgumentException("Player 2 is null");
        }

        int moves = 0;
        if (gems != null) {
            for (Point gemPosition : gems) {
                final int distancePlayer1ToGem = positionPlayer1.distanceTo(gemPosition);
                final int distancePlayer2ToGem = positionPlayer2.distanceTo(gemPosition);

                // player 2 is closer - move player 2
                if (distancePlayer1ToGem > distancePlayer2ToGem) {
                    positionPlayer2 = gemPosition;
                }
                // player 1 is closer or distance is equal - move player 1
                else {
                    positionPlayer1 = gemPosition;
                }
                moves += Math.min(distancePlayer1ToGem, distancePlayer2ToGem);
            }
        }
        return moves;
    }


public class Point {
    private final int _x;
    private final int _y;


    /**
     * Constructor
     *
     * @param x the x position of the current point
     * @param y the y position of the current point
     */
    public Point(final int x, final int y) {
        this._x = x;
        this._y = y;
    }


    /**
     * Determines the distance between the current and the given point. All 8 movement directions
     * are allowed.
     * <p/>
     * This algorithm determines the max distance of x1 -> x2 and y1 -> y2. Because all 8 movement
     * directions are allowed, this is the distance between both points
     *
     * @param otherPoint the other point
     * @return the distance between the current point and the other point
     */
    public int distanceTo(final Point otherPoint) {

        int disX = Math.abs(_x - otherPoint.getX());
        int disY = Math.abs(_y - otherPoint.getY());
        return Math.max(disX, disY);
    }


    /**
     * @return the x position of the current point
     */
    public int getX() {
        return _x;
    }


    /**
     * @return the y position of the current point
     */
    public int getY() {
        return _y;
    }
}
