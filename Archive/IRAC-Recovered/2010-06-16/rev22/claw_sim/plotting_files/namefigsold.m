function namefigs
% NAMEFIGS Name unnamed figures using concatenation of Y axis labels

for hfig = get(0,'Children')'
    fig = get(hfig);
    
    % if this figure is already named, skip it
    if fig.Name
        continue;
    end
    
    labels = [];
    children = fig.Children;
    
    keyboard
    % loop over children, which appear in reverse order of definition
    for ilabel = size(children,1):-1:1;
        label = get(get(children(ilabel),'YLabel'));
        labelstr = label.String;
        
        % tack on next label, if it is non-empty
        if(labelstr)
            % tack on separator after any existing labels
            if(labels)
                labels = [labels ' // '];
            end
            
            labels = [labels labelstr];
        end
    end

    if(labels)
        set(hfig, 'Name', labels);
    end
end