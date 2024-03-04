
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class kenlm_KenlmJNI */

#ifndef _Included_kenlm_KenlmJNI
#define _Included_kenlm_KenlmJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     kenlm_KenlmJNI
 * Method:    ConfigNew
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_kenlm_KenlmJNI_ConfigNew
  (JNIEnv *, jclass);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ConfigDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_kenlm_KenlmJNI_ConfigDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ConfigGetLoadMethod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_kenlm_KenlmJNI_ConfigGetLoadMethod
  (JNIEnv *, jclass, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ConfigSetLoadMethod
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_kenlm_KenlmJNI_ConfigSetLoadMethod
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ModelLoadVirtual
 * Signature: (Ljava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL Java_kenlm_KenlmJNI_ModelLoadVirtual
  (JNIEnv *, jclass, jstring, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ModelDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_kenlm_KenlmJNI_ModelDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ModelBeginSentenceWrite
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_kenlm_KenlmJNI_ModelBeginSentenceWrite
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ModelNullContextWrite
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_kenlm_KenlmJNI_ModelNullContextWrite
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ModelBaseScore
 * Signature: (JJLjava/lang/String;J)F
 */
JNIEXPORT jfloat JNICALL Java_kenlm_KenlmJNI_ModelBaseScore
  (JNIEnv *, jclass, jlong, jlong, jstring, jlong);

/*
 * Class:     kenlm_KenlmJNI
 * Method:    ModelBaseFullScore
 * Signature: (JJLjava/lang/String;J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_kenlm_KenlmJNI_ModelBaseFullScore
  (JNIEnv *, jclass, jlong, jlong, jstring, jlong);

/*