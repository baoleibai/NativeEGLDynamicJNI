
package com.example.nativeegldynamicjni;

import android.R.integer;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;
import android.util.Log;

import java.nio.IntBuffer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * TODO Put here a description of what this class does.
 * 
 * @author b576. Created Nov 18, 2013.
 */

public class MyRenderer implements GLSurfaceView.Renderer {

    private static final String TAG = "bbaiagl";

    private native String nativeGetHelloString();

    private native void nativeDrawFrame();

    private native void nativeSurfaceChanged(int width, int height);

    private native void nativeSurfaceCreated();

    @Override
    public void onDrawFrame(GL10 gl) {
       nativeDrawFrame();
        Log.d(TAG, "onDrawFrame " + nativeGetHelloString());
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        nativeSurfaceChanged(width,height);
        Log.d(TAG, "onSurfaceChanged");
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        nativeSurfaceCreated();
        Log.d(TAG, "onSurfaceCreate");
    }
}
