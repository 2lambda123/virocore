/*
 * Copyright © 2016 Viro Media. All rights reserved.
 */
/*
 * Java JNI wrapper for linking the following classes below across the bridge.
 *
 * Java JNI Wrapper     : com.viro.renderer.CameraJni.java
 * Cpp JNI wrapper      : Camera_JNI.cpp
 * Cpp Object           : VRONodeCamera.cpp
 */
package com.viro.renderer.jni;

/**
 * The Camera defines the point of view of the user in the {@link Scene}. You can display the
 * Scene from the point of view of any {@link Node}. To do this, create a {@link Camera} and attach
 * it to a Node via {@link Node#setCamera(Camera)}. Then make that Node the point of view for the
 * renderer by invoking {@link ViroView#setPointOfView(Node)}.
 * <p>
 * Camera is used to change the user's view of the scene. Note that when in AR or VR modes, the
 * point of view is automatically computed based on the device's rotation and position in the
 * world. This class is primarily for use with {@link ViroViewScene}.
 * <p>>
 * Because Camera is included in the scene graph, it can be moved, animated, and rotated
 * alongside other Nodes. You can also set the position and orientation of the Camera object itself.
 * <p>
 * The initial orientation of the camera is pointing in the negative Z direction: that is, into the
 * screen. If no point of view is set in the {@link Renderer}, the user will be positioned at the
 * origin looking in the negative Z direction.
 * <p>
 */
public class Camera {

    /**
     * Specifies the behavior of the {@link Camera} in VR when rotating the headset.
     */
    public enum RotationType {
        /**
         * Standard camera movement: the camera moves as though it is attached to the headset.
         */
        STANDARD("standard"),

        /**
         * Orbit mode enables the user to orbit around a focal point. This is useful for exploring
         * a single point in a 3D scene from all angles: as the user tilts her head, the camera
         * orbits about that single point.
         */
        ORBIT("orbit");

        private String mStringValue;
        private RotationType(String value) {
            this.mStringValue = value;
        }
        /**
         * @hide
         * @return
         */
        public String getStringValue() {
            return mStringValue;
        }
    };

    long mNativeRef;
    private Vector mPosition = new Vector();
    private Quaternion mRotation = new Quaternion();
    private Vector mOrbitFocalPoint = new Vector();
    private RotationType mRotationType = RotationType.STANDARD;

    /**
     * Construct a new Camera.
     */
    public Camera() {
        mNativeRef = nativeCreateCamera();
    }

    @Override
    protected void finalize() throws Throwable {
        try {
            dispose();
        } finally {
            super.finalize();
        }
    }

    /**
     * Release native resources associated with this Camera.
     */
    public void dispose() {
        if (mNativeRef != 0) {
            nativeDestroyCamera(mNativeRef);
            mNativeRef = 0;
        }
    }

    /**
     * Set the position of this Camera in the coordinate space of its parent {@link Node}.
     *
     * @param position The position as a {@link Vector}.
     */
    public void setPosition(Vector position) {
        mPosition = position;
        nativeSetPosition(mNativeRef, position.x, position.y, position.z);
    }

    /**
     * Get the position of this Camera in the coordinate space of its parent {@link Node}.
     *
     * @return The position as a {@link Vector}.
     */
    public Vector getPosition() {
        return mPosition;
    }

    /**
     * Set the rotation of this Camera. Note the Camera is also rotated by its parent hierarchy
     * in the scene graph. The default orientation is looking in the negative Z direction (into
     * the screen).
     *
     * @param rotation The rotation as a {@link Quaternion}.
     */
    public void setRotation(Quaternion rotation) {
        mRotation = rotation;
        nativeSetRotation(mNativeRef, rotation.x, rotation.y, rotation.z, rotation.w);
    }

    /**
     * Get the rotation of this Camera.
     *
     * @return The rotation as a {@link Quaternion}.
     */
    public Quaternion getRotation() {
        return mRotation;
    }

    /**
     * Set the {@link RotationType} of this Camera in VR. The Camera can either be attached to the
     * headset, in that when the headset moves the camera moves concomitantly, or it can be placed
     * in orbit mode, whereby rotation of the headset causes the camera to orbit around a specific
     * focal point.
     *
     * @param rotationType The {@link RotationType} for the camera.
     */
    public void setRotationType(RotationType rotationType) {
        mRotationType = rotationType;
        nativeSetRotationType(mNativeRef, rotationType.getStringValue());
    }

    /**
     * Get the {@link RotationType} used by the Camera.
     *
     * @return The {@link RotationType}.
     */
    public RotationType getRotationType() {
       return mRotationType;
    }

    /**
     * Set the focal point around which the Camera will orbit when in {@link RotationType#ORBIT}
     * mode.
     *
     * @param focalPoint The focal point as a {@link Vector}.
     */
    public void setOrbitFocalPoint(Vector focalPoint) {
        mOrbitFocalPoint = focalPoint;
        nativeSetOrbitFocalPoint(mNativeRef, focalPoint.x, focalPoint.y, focalPoint.z);
    }

    /**
     * Get the focal point around which the Camera will orbit when in {@link RotationType#ORBIT}
     * mode.
     *
     * @return The focal point as a {@link Vector}.
     */
    public Vector getOrbitFocalPoint() {
        return mOrbitFocalPoint;
    }

    private native long nativeCreateCamera();
    private native void nativeDestroyCamera(long nativeRef);
    private native void nativeSetPosition(long nativeRef, float x, float y, float z);
    private native void nativeSetRotation(long nativeRef, float x, float y, float z, float w);
    private native void nativeSetRotationType(long nativeRef, String rotationType);
    private native void nativeSetOrbitFocalPoint(long nativeRef, float x, float y, float z);
}
