using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Obstacle : MonoBehaviour
{
    public int damage = 1;
    public float speed;
    public GameObject destoyedThing;

    private void Start()
    {
        //anim = GetComponent<Animator>();
    }

    private void Update()
    {
        transform.Translate(Vector2.down * speed * Time.deltaTime);
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
            StartCoroutine("DestoyedAnim");
            other.GetComponent<theJumping>().health -= damage;
            Debug.Log(other.GetComponent<theJumping>().health);
            PlayDestoyed();
            Destroy(gameObject);
        }
    }

    void PlayDestoyed()
    {
        GameObject destroyed = (GameObject)Instantiate(destoyedThing);
        destroyed.transform.position = transform.position;
    }
}
