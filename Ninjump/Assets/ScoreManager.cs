using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreManager : MonoBehaviour
{
    public float score;
    public Text scoreDisplay;

    private void Update()
    {
        scoreDisplay.text = score.ToString();
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.CompareTag("Obstacle"))
        {
            score += 1f;
            Debug.Log(score + "m");
        }
    }
}
