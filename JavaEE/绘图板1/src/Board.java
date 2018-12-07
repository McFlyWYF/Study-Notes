import java.util.ArrayList;
import java.util.List;

public class Board {

    private List<Shape> shapes = new ArrayList();

    public void AddShape(Shape shape) {
        shapes.add(shape);
    }

    public void Refresh() {
        for(Shape shape : shapes) {
            shape.Draw();
        }
    }
}
