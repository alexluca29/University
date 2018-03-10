package view.sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Menu");
        primaryStage.setScene(new Scene(root, 300, 275));
        primaryStage.show();

        //incercare 2

//        FXMLLoader loader = FXMLLoader.load(getClass().getResource("view.sample.fxml"));
//
//        VBox root = loader.load();
//
//        Scene sc = new Scene(root);
//        primaryStage.setScene(sc);
//        primaryStage.setTitle("Menu");
//        primaryStage.show();


        //incercare 3
//        FXMLLoader loader = new FXMLLoader(getClass().getResource("view.sample.fxml"));
//        loader.setController(new ListController());
//        VBox root = (VBox)loader.load();
//
//        Scene scene = new Scene(root);
//        primaryStage.setScene(scene);
//        primaryStage.setTitle("Menu");
//        primaryStage.show();

    }


    public static void main(String[] args) {
        launch(args);
    }
}
