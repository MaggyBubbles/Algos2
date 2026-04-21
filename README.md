#ÜBUNG 2 – AVL-BAUM CHECKLISTE CODE REVIEW

Punkteverteilung:
Die Punkte verteilen sich wie folgt auf die Teilaufgaben:
Implementierung: 15 Punkte
• Einlesen und Aufbau des Baums 3 (Maggy)
• Rekursive Berechnung Balance 3 (Maggy)
• Rekursive Berechnung Min/Max/Avg 2 (Maggy)
• Rekursive Suche Schlüsselwert 3 (Joanna)
• Rekursive Suche Teilbaum 4 (Joanna)

Protokoll: 3 Punkte (Gemeinsam <3)
• Beschreibung der rekursiven Funktionen
• O-Notation und Laufzeitvergleich 2


Teil 1:
In main habe ich nur die Eingabe des Textfiles und das Aufrufen der Funktion, damit es dem "treecheck filename" aus der Angabe entspricht

Ich habe zwei .txt dateien angelegt zum ausprobieren
tree.txt -> ist KEIN avl Baum
avltree.txt -> ist ein avl Baum

Teil 2:
Ich hab den zweiten Teil ergänzt (Suche + Subtree). Kurz wie es funktioniert:

Suche (searchKey): Geht vom Root aus und entscheidet bei jedem Knoten, ob nach links oder rechts gegangen wird (je nachdem ob der Wert kleiner oder größer ist).
Dabei speichere ich den Weg in einem Array, damit am Ende der Pfad ausgegeben werden kann, so wie in der Angabe steht.

Subtree ist in zwei Teile aufgeteilt. isSameTree vergleicht zwei Bäume direkt (Struktur + Werte müssen gleich sein) und searchSubtree läuft durch den ganzen Baum und prüft bei jedem Knoten, ob dort der Subtree beginnt (ruft dafür isSameTree auf). 

Sollte jetzt alles funktionieren, ich hab’s mit eigenen Testfiles ausprobiert (und dafür eine subtree.txt Testdatei erstellt)