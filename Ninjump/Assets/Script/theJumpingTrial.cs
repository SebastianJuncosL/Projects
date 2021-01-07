using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class theJumpingTrial : MonoBehaviour
{
    private Animator anim;

    private Vector2 targetPos;
    public float Xincrement;

    public float speed;
    public float maxX;
    public float minX;

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();

    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
        {
            anim.SetTrigger("isPreJumping");
            StartCoroutine("WaitForJump");       
        }
        if (anim.GetBool("isRunning") == true && transform.position.x < maxX)
        {
                targetPos = new Vector2(transform.position.x + Xincrement, transform.position.y);
                anim.SetTrigger("theJumpingPart");
        }
        transform.position = Vector2.MoveTowards(transform.position, targetPos, speed * Time.deltaTime);
    }

    IEnumerator WaitForJump()
    {
        yield return new WaitForSeconds(1);
        anim.SetBool("isRunning", true);
        
    }
}
