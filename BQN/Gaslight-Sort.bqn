Gsort ← {
	C ← ((-˜+↕∘⊣)÷○(×´1⊸+)↕∘⊣)⚇0
	Ic ← {
		𝕊⁼: 𝕩Ci𝕩;
		m‿n𝕊𝕩:
		⊑-˝(m-↕m) +˝∘(C˘) n-(»1+𝕩)∾˘𝕩
	}
	Ci ← {
		𝕊⁼: 𝕩Ic𝕩;
		0‿n𝕊𝕩: ⟨⟩;
		m‿n𝕊𝕩:
		v←+`(m-1)C(1-m)↓⌽↕n
		k←(v>𝕩)⊐1 # Now for the tricky bit
		k∾(1+k)+(𝕩-1∾1+k)𝕊(𝕩-k⊏0∾v)
	}
	𝕩⋄1
}

# Examples
Gsort 5‿2‿0‿6
Gsort 1‿2‿3‿4
