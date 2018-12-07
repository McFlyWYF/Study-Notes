public class Main {

    public static void main(String[] args) {
        Board board = new Board();

        Rect r1 = new Rect();
        Rect r2 = new Rect();
        Rect r3 = new Rect();

        Cricle c1 = new Cricle();
        Cricle c2 = new Cricle();
        Cricle c3 = new Cricle();

        board.AddShape(r1);
        board.AddShape(r2);
        board.AddShape(r3);

        board.AddShape(c1);
        board.AddShape(c2);
        board.AddShape(c3);

        board.Refresh();

    }
}
