
package com.example.nativeegldynamicjni;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.SurfaceHolder;

public class MyGLSurfaceView extends GLSurfaceView {

    GLSurfaceView.Renderer mRenderer;
    private boolean goNative;

    /**
     * TODO Put here a description of what this constructor does.
     * 
     * @param context
     * @param goNative
     */
    public MyGLSurfaceView(Context context) {
        super(context);
        // TODO Auto-generated constructor stub.
        mRenderer = new MyRenderer();
        // Set the Renderer for drawing on the GLSurfaceView
        setRenderer(mRenderer);
    }

    @Override
    public boolean onTouchEvent(final MotionEvent event) {
        // TODO Auto-generated method stub.
        if (!goNative) {
            queueEvent(new Runnable() {
                public void run() {
                  
                }
            });
            return true;
        } else {
            return false;
        }
    }
}
