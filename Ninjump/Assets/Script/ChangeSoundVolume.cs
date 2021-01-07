using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeSoundVolume : MonoBehaviour
{
    public Slider volume;
    public AudioSource myMusic;
    public AudioSource myEffect;
    private float startingVolume = .5f;

    private void Start()
    {
        volume.value = startingVolume;
    }

    // Update is called once per frame
    void Update()
    {
        myMusic.volume = volume.value;
        myEffect.volume = volume.value;
    }
}
