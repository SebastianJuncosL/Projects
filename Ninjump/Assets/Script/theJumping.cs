using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class theJumping : MonoBehaviour
{
    private Vector2 targetPos;
    public float increment;
    public float speed;
    public float maxX;
    public float minX;
    public float incremenY;
    private bool jumping = false;
    public Animator anim;

    public int health;
    public Text healthDisplay;
    public GameObject gameOver;
    public GameObject obstacle;
    public GameObject scoreManager;
    public GameObject score;
    public GameObject lineas;
    public GameObject pausish;
    public Text finalText;



    // Start is called before the first frame update
    void Start()
    {

    }

    void isJumping()
    {
        if (jumping)
            anim.SetBool("isJumping", true);

        if (!jumping)
            anim.SetBool("isJumping", false);

    }
    // Update is called once per frame
    private void Update()
    {
       healthDisplay.text = health.ToString();
        transform.position = Vector2.MoveTowards(transform.position, targetPos, speed * Time.deltaTime);

        if (health <= 0){
           gameOver.SetActive(true);
            Destroy(score);
            Destroy(gameObject);
            Destroy(pausish);
            lineas.SetActive(false);
            finalText.text= string.Format("{0:N2}",scoreManager.GetComponent<ScoreManager>().score);

        }
        if (Input.touchCount>0 && Input.GetTouch(0).phase == TouchPhase.Began && transform.position.x < maxX)
        {
            targetPos = new Vector2(transform.position.x + increment, transform.position.y + incremenY);
            jumping = true;
            anim.SetBool("isJumping", true);
            FindObjectOfType<AudioManager>().Play("Jumping");
           

        }
        else if (Input.touchCount>0 && Input.GetTouch(0).phase == TouchPhase.Began && transform.position.x > minX)
        {
            targetPos = new Vector2(transform.position.x - increment, transform.position.y + incremenY);
            jumping = true;
            anim.SetBool("isJumping", true);
            FindObjectOfType<AudioManager>().Play("Jumping");

        }

        if (transform.position.y >= 1)
        {
            targetPos = new Vector2(transform.position.x, transform.position.y - 1);
            jumping = false;
            transform.Rotate(Vector3.down * 180);


        }

    }
}