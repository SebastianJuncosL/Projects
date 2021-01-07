using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(Button))]

public class SoundSwitching : MonoBehaviour
{
    public AudioClip circleJump;
    public AudioClip lineJump;
    private AudioClip currentSound;
    private AudioSource source { get { return GetComponent<AudioSource>(); } }

    // Start is called before the first frame update
    void Start()
    {
        gameObject.AddComponent<AudioSource>();
        source.clip = circleJump; 
        source.playOnAwake = false;
        if (Input.touchCount >0)
        {
            //AddListener(() => playSound);
        }


    }
    public void playSound()
    { 
        source.PlayOneShot(circleJump);
    }
}
