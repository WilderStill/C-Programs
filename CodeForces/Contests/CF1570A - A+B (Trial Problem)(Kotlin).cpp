import java.util.Scanner
fun main()
{
    val read=Scanner(System.`in`)
    var t=read.nextInt()
    while(t>0)
	{
        var a=read.nextInt()
        var b=read.nextInt()
        println(a+b)
        t--
    }
}
