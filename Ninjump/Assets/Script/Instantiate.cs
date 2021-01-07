using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Instantiate : MonoBehaviour
{
    private Vector2 screenBounds;
    public float respawnTime = 1.0f;
    public GameObject A;
    // Start is called before the first frame update
    void Start()
    {
        screenBounds = Camera.main.ScreenToWorldPoint(new Vector2(Screen.width, Screen.height));
        StartCoroutine(edificios());

    }

    // Update is called once per frame
    void Update()
    {
       
        
    }

    private void spawnEdificios()
    {
        GameObject a = Instantiate(A) as GameObject;
        a.transform.position = new Vector2(screenBounds.x * -2, Random.Range(-screenBounds.x, -screenBounds.y));
    }

    IEnumerator edificios()
    {
        while (true)
        {
            yield return new WaitForSeconds(respawnTime);
            spawnEdificios();

        }
    }
}
