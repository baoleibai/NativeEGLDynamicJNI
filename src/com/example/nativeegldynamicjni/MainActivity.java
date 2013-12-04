
package com.example.nativeegldynamicjni;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.app.Activity;
import android.view.Window;
import android.view.WindowManager;

/**
 * TODO Put here a description of what this class does.
 *
 * @author b576.
 *         Created Nov 25, 2013.
 */
public class MainActivity extends Activity {

    /**
     * TODO Put here a description of this field.
     */
    GLSurfaceView mGLView;
    static {
        System.loadLibrary("myegl_jni");
    }
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE); 
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN); // (NEW)

        this.mGLView = new MyGLSurfaceView(this);  
        setContentView(this.mGLView);
    }
}
