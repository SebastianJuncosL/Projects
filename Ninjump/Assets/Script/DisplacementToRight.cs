using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DisplacementToRight : MonoBehaviour
{
    private Vector2 targetPos;
    public float Yincrement;

    public float speed;
    public float maxX;
    public float minX;

    void Update()
    {
        transform.position = Vector2.MoveTowards(transform.position, targetPos, speed * Time.deltaTime);

            if (Input.GetKeyDown(KeyCode.RightArrow) && transform.position.x< maxX  ) 
            {
                targetPos = new Vector2(transform.position.x + Yincrement, transform.position.y);
            }
        
        
    }
}
