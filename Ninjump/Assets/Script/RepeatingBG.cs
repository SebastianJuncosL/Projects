using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RepeatingBG : MonoBehaviour
{
    float scrollSpeed = 15f;

    Vector2 startpos;

    private void Start()
    {
        startpos = transform.position;
    }

    private void Update()
    { 
        float newPos = Mathf.Repeat(Time.time * scrollSpeed, 92f);
        transform.position = startpos + Vector2.down * newPos;
    }
}