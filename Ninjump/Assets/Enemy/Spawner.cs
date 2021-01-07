using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    public GameObject obstacle;
    public float timeBtwSpawn;
    public float startTimeSpawn;
    private Vector2 where;
    public float minTime;
    public float decreaseTime;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {

        if(timeBtwSpawn <= 0)

        {
            int rand = Random.Range(0, 30);
            print(rand);
            where = new Vector2(rand, transform.position.y);
            Instantiate(obstacle, where, Quaternion.identity);
            timeBtwSpawn = startTimeSpawn;
            if(startTimeSpawn > minTime)
            {
                startTimeSpawn -= decreaseTime;
            }
        }
        else
        {
            timeBtwSpawn -= Time.deltaTime;
        }
    }
}
