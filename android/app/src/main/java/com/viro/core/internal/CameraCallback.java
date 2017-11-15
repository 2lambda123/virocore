/*
 * Copyright (c) 2017-present, ViroMedia, Inc.
 * All rights reserved.
 */
 package com.viro.core.internal;

/**
 * Callback interface used to get camera related information from the
 * renderer asynchronously.
 */
public interface CameraCallback {
    void onGetCameraOrientation(float posX, float posY, float posZ,
                                float rotEulerX, float rotEulerY, float rotEulerZ,
                                float forwardX, float forwardY, float forwardZ,
                                float upX, float upY, float upZ);
}
