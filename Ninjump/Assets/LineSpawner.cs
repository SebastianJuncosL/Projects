﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LineSpawner : MonoBehaviour
{
    public GameObject[] obstaclePattterns;

    private float timeBtwSpawn;
    public float startTimeBtwSpawn;
    public float decreaseTime;
    public float minTime = 0.65f;


    private void Update()
    {
    
        if (timeBtwSpawn <= 0)
        {
            int randX = Random.Range(0, 30);
            Vector2 where = new Vector2(randX, transform.position.y);
            Instantiate(obstaclePattterns[0], where, Quaternion.identity);
            timeBtwSpawn = startTimeBtwSpawn;
            if (startTimeBtwSpawn > minTime)
            {
                startTimeBtwSpawn -= decreaseTime;
            }
        }
        else
        {
            timeBtwSpawn -= Time.deltaTime;
        }
    }
}
